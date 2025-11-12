#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll a[5010];
const ll mod=998244353;
ll ans=0;
bool v[5010];
bool h[5010];
bool vmax[50010];

void dfs(int now,ll ljh,ll maxx,ll sl)
{
	v[now]=true;
	if((sl>=3)&&(ljh>(2*maxx))&&(h[ljh]==false||vmax[2*maxx]==false))
	{
		h[ljh]=true;vmax[2*maxx]=true;ans=((ans+1)%mod); 	
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=now&&v[i]==false)
		{
			v[i]=true;
			dfs(i,ljh,maxx,sl);	
			v[i]=false;
		}
		
	}
	ll tljh=ljh+a[now];
	ll tmaxx=max(maxx,a[now]);
	for(int i=1;i<=n;i++)
		if(i!=now&&v[i]==false)
		{
			v[i]=true;
			dfs(i,tljh,tmaxx,sl+1);	
			v[i]=false;
		}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	memset(vmax,false,sizeof(vmax));
	for(int i=1;i<=n;i++)
	{
		v[i]=false;h[i]=false;
		scanf("%lld",&a[i]);
	}
	if(n<3) printf("0");
	else if(n==3)
	{
		ll tt=max(max(a[1],a[2]),a[3]);
		if((a[1]+a[2]+a[3])>(2*tt)) 
		printf("1");
		else printf("0");
	}
	else{
		dfs(1,0,0,0);
		printf("%lld",ans);
	}
	return 0;
}
