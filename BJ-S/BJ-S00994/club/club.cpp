#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
ll t,n,a[100005][5],best[100005];
struct _
{
	ll i,x;
	bool operator<(_ ot)
	{
		return x<ot.x;
	}
}diff[100005];
int main()
{
	faster;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n;
		ll c[]={0,0,0,0},ans=0;
		for (ll i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ll mx=max(max(a[i][1],a[i][2]),a[i][3]);
			if (mx==a[i][1])
			{
				best[i]=1;
				c[1]++;
				diff[i]={i,min(a[i][1]-a[i][2],a[i][1]-a[i][3])};
			}
			else if (mx==a[i][2])
			{
				best[i]=2;
				c[2]++;
				diff[i]={i,min(a[i][2]-a[i][1],a[i][2]-a[i][3])};
			}
			else
			{
				best[i]=3;
				c[3]++;
				diff[i]={i,min(a[i][3]-a[i][1],a[i][3]-a[i][2])};
			}
			ans+=mx;
		}
		ll mx=max(max(c[1],c[2]),c[3]);
		ll cnt=mx-n/2;
		sort(diff+1,diff+1+n);
		for (ll i=1;i<=n;i++)
		{
			if (c[best[diff[i].i]]==mx&&cnt>0)
			{
				ans-=diff[i].x;
				cnt--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}//100
