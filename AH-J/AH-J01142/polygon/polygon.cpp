#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,i,ans,nn,sum,mx=-114514,cnt;
int a[5005],c[5005];
bool vis[5005];
void dfs(int k,int x,int sum,int mx)
{
	if(sum>2*mx)
	{
		if(k==0&&x>=3)
			ans++;
		ans%=MOD;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		vis[i]=true;
		//cout<<a[i]<<" ";
		dfs(k-1,x+1,sum+a[i],max(mx,a[i]));
		vis[i]=false;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=3;i<=n;i++)
	{
		dfs(i,0,0,0);
	}
	cout<<ans;
	return 0;
}
