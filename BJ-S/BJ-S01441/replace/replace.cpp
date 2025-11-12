#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
ll n,w,ans;
struct node{
	string a1,a2;
};
node a[N],q[N];
ll check(ll x,ll y)
{
	ll z=0;
	ll yl=a[y].a1.size();
	ll xl=q[x].a1.size();
	for(ll i=0;i<=xl-yl;i++)
	{
		ll w1=i;
		bool s=1;
		for(ll j=0;j<yl;j++)
		{
			if(a[y].a1[j]!=q[x].a1[w1+j])
			{
				s=0;
				break;
			}
		}
		if(s==1)
		{
			string f1=q[x].a1;
			string f2=q[x].a2;
			string f3="";
			ll rl=f2.size();
			f1[w1]='K';
			for(ll j=0;j<xl;j++)
			{
				if(f1[j]=='K')
				{
					f3+=a[y].a2;
					j+=yl-1;
				}
				else
				{
					f3+=f1[j];
				}
			}
			if(f3.size()!=f2.size())
			{
				continue;
			}
			ll rg=1;
			for(ll j=0;j<rl;j++)
			{
				if(f3[j]!=f2[j])
				{
					rg=0;
					break;
				}
			}
			if(rg==1)
			{
				z++;
			}
		}
	}
	return z;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>w;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].a1>>a[i].a2;
	}
	for(ll i=1;i<=w;i++)
	{
		cin>>q[i].a1>>q[i].a2;
	}
	for(ll i=1;i<=w;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			ans+=check(i,j);
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
