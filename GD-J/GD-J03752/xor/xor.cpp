#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500050],b[500050];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;++i) 
	{
		scanf("%lld",&a[i]);
		b[i]=b[i-1];
		b[i]^=a[i];
	}
	if(n*n>=100000000)
	{
		ll ans=0;
		for(ll i=2;i<=n;++i)
		{
			if(a[i]^a[i-1]==k) 
			{
				++ans; 
				++i;
			}
		 }
		cout<<ans<<'\n';
	}
	else
	{
		ll y=0,ans=0;
		for(ll i=1;i<=n;++i)
		{
			if(i<=y) continue;
			for(ll j=i;j<=n;++j) 
			{
				int x=b[i-1]^b[j];
				if(x==k) 
				{
					y=j;
					++ans;
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
