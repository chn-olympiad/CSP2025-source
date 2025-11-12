#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct abc
{
	ll a,b;	
}p[1000001];
ll n,k;
ll o[100001];
ll okok[100001];
ll cnt,ok=-1e9;
void dfs(ll a,ll b)
{
	if(a==b)
	{
		if(o[a]==k) 
		{
			p[++cnt].a=a;
			p[cnt].b=b;
			return;
		}
		else return;
	}
	int sum=o[a];
	for(int i=a+1;i<=b;i++)
	{
		sum=(sum^o[i]);
	}
	if(sum==k)
	{
		p[++cnt].a=a;
		p[cnt].b=b;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>o[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;j++)
		{
			dfs(i,j);
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		ll y=0;
		for(int j=i,ok1;j<=cnt;j++)
		{
			ok1=0;
			for(int z=p[j].a;z<=p[j].b;z++)
			{
				if(okok[z]==1) 
				{
					ok1=1;
					break;
				}	
			}
			if(ok1==0)
			{
				y++;
				for(int z=p[j].a;z<=p[j].b;z++)
				{
					okok[z]=1;
				}
			}
		}
		ok=max(ok,y);
		for(int j=1;j<=n;j++) okok[j]=0;
	}
	cout<<ok;
	return 0;
}

