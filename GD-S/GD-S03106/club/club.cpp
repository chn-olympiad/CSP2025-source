#include<bits/stdc++.h>
#define ll long long
#define N 110000
using namespace std;

ll T,n,ans=-INT_MAX;
ll a[N][5],dp[N][5];

void dfs(ll numa,ll numb,ll numc,ll i,ll cnt)
{
	if(i==n+1)
	{
		ans=max(ans,cnt);
		return ;
	}
	if(numa+1<=n/2) dfs(numa+1,numb,numc,i+1,cnt+a[i][1]);
	if(numb+1<=n/2) dfs(numa,numb+1,numc,i+1,cnt+a[i][2]);
	if(numc+1<=n/2) dfs(numa,numb,numc+1,i+1,cnt+a[i][3]);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=-INT_MAX;
		cin>>n;
		if(n<=30)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			dfs((ll)0,(ll)0,(ll)0,(ll)1,(ll)0);
			cout<<ans<<"\n";
		}
		else
		{
			ans=0;
			for(int i=1;i<=n;i++)
			{
				ll x,y;
				cin>>a[i]>>x>>y;
			}
			sort(a+1,a+1+n);
			for(int i=n;i>=n/2;i--)
			{
				ans+=a[i];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
