#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans;
int a[5010];
void dfs(int k,int sum,int ma)
{
	if(k==n+1)
	{
		if(sum>ma*2) ans++;
		return ;
	}
	dfs(k+1,sum+a[k],max(ma,a[k]));
	dfs(k+1,sum,ma);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
