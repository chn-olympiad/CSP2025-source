#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll a[500010],h[500010];
struct node{
	ll l,r;
}p[500010];
bool cmp(node q,node w)
{
	if(q.r!=w.r)return q.r>w.r;
	return q.l>w.l;
}
ll f(ll iu,ll ui)
{
	return (h[iu-1]^h[ui]);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,po=1;
	cin>>n;
	h[0]=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)po=0;
		h[i]=h[i-1]^a[i];
	}
	if(po==1&&(k==0||k==1))
	{
		if(k==1)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1)ans+=1;
			cout<<ans;
		}
		if(k==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{	
				if(a[i]==0)ans+=1;
				if(a[i]==1&&a[i+1]==1)
				{
					ans+=1;
					i+=1;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	
	return 0;
}
