#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sz[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::cin.tie(0);
	ll n,k,ans=0,jl=0;
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>sz[i];
		if(i!=1&&i-1!=jl) sz[i]=sz[i]^sz[i-1];
		if(sz[i]==k)
		{
			ans++;
//			sz[i]=0;
			jl=i;
		}
		else 
		{
			ll bl=sz[i];
			for(ll j=jl+1;j<=i;j++)
			{
				if(j==i) break;
				bl=bl^sz[j];
				if(bl==k) 
				{
					ans++;
//					sz[i]=0;
					jl=i;
					break;
				}
			}
		}
//		cout<<sz[i]<<' ';
	}
//	for(ll i=1;i<=n;i++)
//	{
//		if(sz[i]==k)
//		{
//			ans++;
//			jl=i;
//		}
//		else 
//		{
//			ll bl=sz[i];
//			for(ll j=jl;j<=i;j++)
//			{
//				if(j==i) break;
//				bl=bl^sz[j];
//				if(bl==k) 
//				{
//					ans++;
//					jl=i;
//					break;
//				}
//			}
//		}
//	}
	cout<<ans;
	return 0;
}

