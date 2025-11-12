#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct road{
	ll u,v,w;
};
const ll MAXN=1e5+5,MAXM=1e6+5;
ll n,m,k,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	road r[MAXM];
	ll c[MAXN];
	for(ll i=0;i<m;i++)
	{
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	ll cnt1=0,cnt2=0;
	for(ll i=0;i<n;i++)
	{
		cin>>c[i];
	}
	for(ll i=0;i<n;i++)
	{
		if(i%(n+1)==0)
		{
			cnt1+=c[i];
			c[i]=-1;
		}
	}
	sort(c,c+n);
	for(ll i=0;i<n;i++)
	{
		if(c[i]!=-1)
		{
			cnt1=cnt1+c[i]+c[i+1];
			break;
		}
	}
	for(ll i=0;i<m;i++)
	{
		cnt2+=r[i].w;
	}
	cout<<min(cnt1,cnt2);
	return 0;
} 
