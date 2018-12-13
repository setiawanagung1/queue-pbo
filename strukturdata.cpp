
#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

typedef struct data{
	string NamaPemain;
	string PosisiPemain;
	int NoPemain;
}dData;

class simpul
{
	public :
		dData Datapemain;
		simpul* pBerikutnya;
		
		
		simpul(string nP,string pP, int np)
		{
			Datapemain.NamaPemain = nP;
			Datapemain.PosisiPemain = pP;
			Datapemain.NoPemain = np;
			pBerikutnya = NULL;
		}
		
		void tampilSimpul(){cout << Datapemain.NoPemain << "-->" << Datapemain.NamaPemain << "-->" << Datapemain.PosisiPemain<<endl;}
};

class linkedlist
{
	private :
		simpul* pPertama;
		simpul* pAkhir;
	
	public :
		linkedlist() : pPertama(NULL)
		{}
		
		~linkedlist(){
			simpul* pSekarang = pPertama;
			while(pSekarang!=NULL)
			{
				simpul* pLama = pSekarang;
				pSekarang = pSekarang->pBerikutnya;
				delete pLama;
			}
		}
		
		bool apaKosong(){
			return (pPertama==NULL);
		}
		
		void sisipAkhir(string nP, string pP, int np){
			simpul* pSimpulBaru = new simpul(nP,pP,np);
			if(apaKosong())
			{
				pPertama = pSimpulBaru;
			}
			else
			{
				pAkhir->pBerikutnya=pSimpulBaru;
			}
			pAkhir=pSimpulBaru;
		}
		
		void hapusPertama(){
			simpul* pTemp = pPertama;
			pPertama = pPertama->pBerikutnya;
			delete pTemp;
		}
		
		void tampilSenarai(){
			simpul* pSekarang = pPertama;
			if(pSekarang==NULL)
			{
				cout << "STACK KOSONG!!!";
			}
			while(pSekarang!=NULL)
			{
				pSekarang->tampilSimpul();
				pSekarang = pSekarang->pBerikutnya;
			}
			cout << endl;
		}
};

class queuelist{
	private :
		linkedlist* pSenarai;
	
	public :
		queuelist()
		{
			pSenarai = new linkedlist;
		}
		
		~queuelist()
		{
			delete pSenarai;
		}
		
		void push(string nP, string pP, int np)
		{
			pSenarai->sisipAkhir(nP,pP,np);
		}
		
		void pop()
		{
			pSenarai->hapusPertama();	
		}
		
		bool apaKosong()
		{
			return (pSenarai->apaKosong());
		}
		
		void tampilTumpukan()
		{
			pSenarai->tampilSenarai();
		}
};

int main(){
	queuelist queue;
	int pilih, no;
	string nama, posisi;
	do 
	{	cout<<"---------------------------------------------"<<endl;
		cout<<"QUEUE MENGGUNAKAN LINKED LIST"<<endl<<endl;
		cout<<"1. Enqueue"<<endl;
		cout<<"2. Dequeue"<<endl;
		cout<<"3. Tampil"<<endl;
		cout<<"4. Exit"<<endl<<endl;
		cout<<"Masukkan Pilihan (1-4): ";
		cin>>pilih;
		cout<<"---------------------------------------------"<<endl;
	
		switch(pilih)
		{
			case 1 :
				cout<<"\nMasukkan Nomer Punggung Pemain : "; cin>>no;
				cin.ignore(256,'\n');
				cout<<"Masukkan Nama Pemain : "; getline(cin,nama);
				cout<<"Masukkan Posisi Pemain : "; getline(cin,posisi);
				queue.push(nama,posisi,no);
				break;
				
			case 2 :
				queue.pop();
				break;
			
			case 3 :
				queue.tampilTumpukan();
				break;
				
			case 4 :
				exit(0);
				break;
				
			default :
				cout << "pilihan yang anda masukkan salah !"<<endl;
		}
	} while (true);
	getch();
	return 0;
}

