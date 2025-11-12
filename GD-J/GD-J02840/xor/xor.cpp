#include<bits/stdc++.h>
using namespace std;
bool Mst;
const int N=5e5+10,V=1<<21;
int n,k,a[N],b[N];
int mxf[V+10];
int f[N];

bool Med;
signed main()
{
//	cerr<<"Memory:"<<(&Med-&Mst)/1048576.0<<" Mib.\n";
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=V;i++) mxf[i]=-1e8;
	for(int i=1;i<=n;i++)
	{
		f[i]=max(f[i-1],mxf[b[i]^k]+1);
		mxf[b[i]]=max(mxf[b[i]],f[i]);
	}
	cout<<f[n]<<endl;
}
/*
xor
g++ make.cpp -o make.exe
g++ xor.cpp -o xor.exe
g++ pai_of_xor.cpp -o pai_of_xor.exe
g++ check.cpp -o check.exe
./make.exe
./xor.exe
./pai_of_xor.exe
./check.exe

*/
