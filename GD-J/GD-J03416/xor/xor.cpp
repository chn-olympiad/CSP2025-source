#include<bits/stdc++.h>
#define ll long long
#define N 510000
using namespace std;

ll n,k,l=1;
ll ans=0;
ll a[N],b[N];
bool vis[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	b[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(ll i=1;i<=n;i++)
	{
		if(a[i]==k) 
		{
			ans++;
			l=i+1;
			continue ;
		}
		for(ll j=i-1;j>=l-1;j--)
		{
			ll cnt=b[j]^b[i];
			if(cnt==k)
			{
				l=i+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
