#include<bits/stdc++.h>
#define ll long long
#define INF 214748364719260817ll
using namespace std;
ll t,n;
int main()
{
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll sum=0;
		priority_queue<ll>s[3];
		ll a[3];
		for(ll i=1;i<=n;++i)
		{
			ll maxn=0;
			for(ll j=0;j<3;++j)
				cin>>a[j],maxn=max(maxn,a[j]);
			sum+=maxn;
			for(ll j=0;j<3;++j)
				if(a[j]==maxn)
				{
					ll mv=0;
					for(ll k=0;k<3;++k)
						if(k!=j)mv=max(mv,a[k]);
					s[j].emplace(mv-maxn);
					break;
				}
		}
		for(ll i=0;i<3;++i)
			while(s[i].size()>n/2)sum+=s[i].top(),s[i].pop();
		cout<<sum<<'\n';
	}
}