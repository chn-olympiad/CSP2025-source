#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],f[N],cnt;
int n,mod=998244353;;
void dfs(int u,int sum,int maxn)
{
	if(u==n+1)
	{
		if(maxn*2<sum) cnt++;
		cnt%=mod;
		return;
	}
	dfs(u+1,sum+a[u],a[u]);
	dfs(u+1,sum,maxn);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<cnt%mod;
	return 0;
}