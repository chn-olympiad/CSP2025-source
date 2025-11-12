#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[100005],b[100005],c,ans,d;
map<ll,ll> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		mp[b[i-1]]=i;
		if(a[i]==k)
		{
			c=i;
			ans++;
		}
		else if(mp[b[i]^k]!=0&&k!=0)
		{
			if(mp[k^b[i]]>c)
			{
				c=i;
				mp[k^b[i]]=0;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
