#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+7;
ll t,n;
ll a[N][7];
ll cnt[7];
ll ans=0;
void dfs(ll k,ll sum)
{
	if(k>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(cnt[1]<(n/2))
	{
		cnt[1]++;
		dfs(k+1,sum+a[k][1]);
		cnt[1]--;
	}
	if(cnt[2]<(n/2))
	{
		cnt[2]++;
		dfs(k+1,sum+a[k][2]);
		cnt[2]--;
	}
	if(cnt[3]<(n/2))
	{
		cnt[3]++;
		dfs(k+1,sum+a[k][3]);
		cnt[3]--;
	}
	dfs(k+1,sum);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		cnt[1]=cnt[2]=cnt[3]=0;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
