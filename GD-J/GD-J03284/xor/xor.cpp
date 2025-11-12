#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k;
ll a[500050];
bool v[1010];
ll yh[1010][1010];
ll maxx=-1;

void dfs(ll now,ll ans)
{
	maxx=max(maxx,ans);
//	v[now]=true;
	for(int i=now;i<=n;i++)
	{
		if(yh[now][i]==k)
		{
			maxx=max(maxx,ans+1);	
			if(i+1<=n&&v[i+1]==false)
			{
				v[i+1]=true;
				dfs(i+1,ans+1);
			}
		}
		else if(i+1<=n&&v[i+1]==false)
		{v[i+1]=true;dfs(i+1,ans);}
//		v[i+1]=false;
	}
}

int main()
{ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool pf=true;
	memset(v,false,sizeof(v));
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1) pf=false;
	}
	if(k==0&&pf)
	{
		printf("%lld",n/2);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ll t=a[i];
		for(int j=0;j+i<=n;j++)
		{
			if(j!=0) t=t^a[i+j];
			yh[i][i+j]=t;
			yh[i+j][i]=t;
		}
	}
	v[1]=1;
	dfs(1,0);
	printf("%lld",maxx);
	return 0;
}
