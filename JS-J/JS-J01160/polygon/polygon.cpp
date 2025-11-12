#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10,mod=998244353;
int n,a[maxn],ans;
void dfs(int k,int m,int mx,int t)
{
	if(k>n)
	{
		if(m>2*mx&&t>=3)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(k+1,m+a[k],max(a[k],mx),t+1);
	dfs(k+1,m,mx,t);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}