#include<bits/stdc++.h>
using namespace std;
bool Mst;
int n,m;
int a[100010];
int ord[100010];

bool cmp(int x,int y)
{
	return a[x]>a[y];
}

bool Med;
signed main()
{
//	cerr<<"Memory:"<<(&Med-&Mst)/1048576.0<<" Mib.\n";
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>a[i];
		ord[i]=i;
	}
	sort(ord+1,ord+1+len,cmp);
	int rk=0;
	for(int i=1;i<=len;i++)
	{
		if(ord[i]==1)
		{
			rk=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(rk>n)
		{
			rk-=n;
			continue;
		}
		if(i&1)
		{
			cout<<i<<" "<<rk<<endl;
			return 0;
		}
		cout<<i<<" "<<n-rk+1<<endl;
		return 0;
	}
}
/*
seat
g++ make.cpp -o make.exe
g++ seat.cpp -o seat.exe
g++ pai_of_seat.cpp -o pai_of_seat.exe
./make.exe
./seat.exe
./pai_of_seat.exe

*/
