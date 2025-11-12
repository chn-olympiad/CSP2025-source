# include <bits/stdc++.h>
# define ll long long
using namespace std;
const ll N =1e5+10;
ll t,d[N][4],n,ans;
void dfs(ll po1,ll po2,ll po3,ll x,ll sum)
{
	if(x>n){ans=max(ans,sum);return;}
	if(po1+1<=n/2)dfs(po1+1,po2,po3,x+1,sum+d[x][1]);
	if(po2+1<=n/2)dfs(po1,po2+1,po3,x+1,sum+d[x][2]);
	if(po3+1<=n/2)dfs(po1,po2,po3+1,x+1,sum+d[x][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		ans=-1;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
		scanf("%lld",&d[i][j]);
		dfs(0,0,0,1,0);
		cout<<ans<<endl;
	}
	return 0;
}