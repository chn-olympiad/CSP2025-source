#include<bits/stdc++.h>
#define int long long
using namespace std;
bool Mst;
const int N=5010;//V=N
const int mod=998244353;
int n,a[N];
int f[N+10][N+10];//choose a<i,sum=j
int p2[N+10];//pow of 2 (mod 998...)
int sum[N+10];

int mo(int x)
{
	return x>=mod?x-mod:x;
}

bool Med;
signed main()
{
//	cerr<<"Memory:"<<(&Med-&Mst)/1048576.0<<" Mib.\n";
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	p2[0]=1;
	for(int i=1;i<=n;i++)
	{
		p2[i]=p2[i-1]*2%mod;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f[1][0]=1;
	for(int i=2,l=1;i<N;i++)
	{
		for(int j=0;j<=N;j++) f[i][j]=f[i-1][j];
		while(l<=n && a[l]==i-1)
		{
			for(int j=N;j>=a[l];j--)
			{
				f[i][j]=mo(f[i][j]+f[i][j-a[l]]);
			}
			l++;
		}
		sum[i]=l-1;
	}
	int ans=0;
	for(int i=1;i<N;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			cnt+=a[j]==i;
		}
		if(!cnt) continue;
		int tmp=p2[sum[i]]; 
		for(int j=0;j<=i;j++)
		{
			tmp=mo(tmp+mod-f[i][j]);
		}
		ans=ans+tmp*cnt%mod;
		ans=ans+cnt*(cnt-1)/2%mod*(p2[sum[i]]-1)%mod;
		cnt=(p2[cnt]-1-cnt-(cnt)*(cnt-1)/2)%mod;
		cnt=(cnt+mod)%mod;
		ans=(ans+cnt*p2[sum[i]])%mod;
//		cerr<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
}
/*
polygon
5
2 2 3 8 10

g++ make.cpp -o make.exe
g++ polygon.cpp -o polygon.exe
g++ pai_of_polygon.cpp -o pai_of_polygon.exe
g++ check.cpp -o check.exe
./polygon.exe
./check.exe

./make.exe
./pai_of_polygon.exe

*/
