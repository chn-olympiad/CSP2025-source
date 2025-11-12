#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
int fath[1100000+5];
int gtf(int i)
{
	return fath[i]==i?i:fath[i]=gtf(fath[i]);
}
struct node
{
	ll x,y,z;
} eg[1000000+5];
bool cmp(node x,node y)
{
	return x.z<y.z;
}
node pmr[1100000+5];
ll c[10+5];
ll cct[10+5][10000+5];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
	{
		cin>>eg[i].x>>eg[i].y>>eg[i].z;
	}
	for(ll i=0;i<k;i++)
	{
		cin>>c[i];
		for(ll j=1;j<=n;j++)
		{
			cin>>cct[i][j];
		}
	}
	sort(eg+1,eg+m+1,cmp);
	for(ll i=1;i<=n;i++) fath[i]=i;
	ll tmpc=0;
	for(ll i=1;i<=m;i++)
	{
		ll fx=gtf(eg[i].x),fy=gtf(eg[i].y);
		if(fx!=fy)
		{
			fath[fx]=fy;
			pmr[++tmpc]=eg[i];
		}
	}
	ll ans=2e18;
	for(ll i=0;i<(1ll<<k);i++)
	{
		ll cur=n-1;
		for(ll j=1;j<=n-1;j++)
		{
			eg[j]=pmr[j];
//			cout<<eg[j].z<<"$\n";
		}
		ll cst=0;
		ll cnt=0;
		for(ll j=0;j<k;j++)
		{
			if((1ll<<j)&i)
			{
				cnt++;
				cst+=c[j];
				for(ll w=1;w<=n;w++)
				{
					eg[++cur]={n+j+1,w,cct[j][w]};
				}
			}
		}
		sort(eg+1,eg+cur+1,cmp);
		for(ll j=1;j<=k+n;j++) fath[j]=j;
		for(ll j=1;j<=cur;j++)
		{
			ll fx=gtf(eg[j].x),fy=gtf(eg[j].y);
			if(fx!=fy)
			{
				fath[fx]=fy,cst+=eg[j].z;
//				cout<<eg[i].z<<"$\n";
			}
		}
		ans=min(ans,cst);
//		cout<<i<<' '<<cst<<' '<<cur<<"#\n";
	}
	cout<<ans<<"\n";
	return 0;
}
