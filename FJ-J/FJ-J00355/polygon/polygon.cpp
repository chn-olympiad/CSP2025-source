#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5010,mod=998244353;
int n,res,a[N],c[N][N];
void init()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			if(!j)c[i][j]=1;
			else c[i][j]=((LL)c[i-1][j]+c[i-1][j-1])%mod;
		}
}
void dfs(int u,int sum,int last)
{
	if(u==n+1)
	{
		if(sum>2*last)res=(res+1)%mod;
		return;
	}
	dfs(u+1,sum,last);
	dfs(u+1,sum+a[u],a[u]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int p=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=p)p=0;
	}
	if(!p)
	{
		sort(a+1,a+n+1);
		dfs(1,0,0);
	}
	else
	{
		init();
		int res=0;
		for(int i=3;i<=n;i++)res=((LL)res+c[n][i])%mod;
	}
	cout<<res;
	return 0;
}
