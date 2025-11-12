#include<bits/stdc++.h>
#define N 5010
#define ll long long
#define mod 998244353
using namespace std;
int n;
int a[N];
ll ans;
void dfs(int x,int bs,int sum,int maxn)
{
	sum+=a[x];
	if(sum>(maxn<<1))
	{
		ans=(ans+1)%mod;
	}
	for(int i=x+1;i<=n;i++)
	{
		dfs(i,bs+1,sum,a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dfs(i,1,0,a[i]);
	}
	cout<<ans;
}
//5
//1 2 3 4 5
//
//5
//2 2 3 8 10
