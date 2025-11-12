#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int t,int s,int mx,int m)
{
		//cout<<t<<" "<<s<<" "<<mx<<" "<<m<<'\n';
	if(m>=3&&s>mx*2) ans=(ans+1)%998244353;
	for(int i=t+1;i<=n;i++)
	{
		int p=max(a[i],mx);
		dfs(i,s+a[i],p,m+1);
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
