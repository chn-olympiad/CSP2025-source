#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
const int MOD=998244353;
ll n,m,a[N],f[N],ans=0;
void dfs(int k,int p,ll h,int s)
{
	if(p>=3)
	{
		if(h>s*2)
		 ans++;
		ans%=MOD;
	}
	for(int i=k+1;i<=n;i++)
	{
		dfs(i,p+1,h+a[i],a[i]);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
