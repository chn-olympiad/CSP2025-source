#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mode=998244353;
int n,m;
char c[505];
int a[505],q[505];
bool f[505];
int jie[505];
int ans;
int b[505];
void dg(int x,int s,int sum)
{
	if(sum>=m)
	{
		ans=(ans+jie[n-x])%mode;
		return;
	}
	if(x==n)
	{
		if(sum>=m) ans=(ans+1)%mode;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1) continue;
		if(s>=a[i]||c[x]=='0')
		{
			f[i]=1; b[x+1]=i;
			dg(x+1,s+1,sum);
			f[i]=0;
		}
		else
		{
			f[i]=1; b[x+1]=i;
			dg(x+1,s,sum+1);
			f[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>c; int clen=strlen(c); jie[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		jie[i]=jie[i-1]*i%mode;
	}
	dg(0,0,0);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2


10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
