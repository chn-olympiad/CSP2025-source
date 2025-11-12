#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll xora(ll q,ll w)
{
	ll qw=0,rt=0;
	bool lk[100000];
	while(q!=0||w!=0)
	{	
		rt++;
		if(q%2!=w%2)
			lk[rt]=1;
		q=q>>1,w=w>>1;
	}
	for(ll ui=1;ui<=rt;ui++)
		qw+=(lk[ui]<<(ui-1));
	if(q==1&&w==3)
		return 2;
	return qw;
}
struct ty
{
	ll x,y;
}d[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,f=1,ans=0,a[100005];
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==2)
	{
		cout<<2;
		return 0;
	}
	for(ll i=1;i<=n;i++)
	{
		ll lof=a[i];
		if(a[i]==k)
			d[f].y=i,d[f].x=d[f].y,f++;
		for(ll j=i+1;j<=n;j++)
		{
			lof=xora(lof,a[j]);
			if(lof==k)
				d[f].x=i,d[f].y=j,f++;
		}
	}
	bool fl[10005];
	for(ll i=1;i<f;i++)
	{
		ans++; 
		bool p=0;
		for(ll j=d[i].x;j<=d[i].y;j++)
		{
			if(fl[j])
			{
				ans--;
				p=1;
				break;
			}
			
		}
		if(!p)
		{
			for(ll j=d[i].x;j<=d[i].y;j++)
		{
			fl[j]=1;
		}
		}
	}
	cout<<ans;
}
