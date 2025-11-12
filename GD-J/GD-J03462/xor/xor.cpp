#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll n,k,l=1,r,ans,sum[maxn],a[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[1],sum[1]=a[1],r=n;
	for(ll i=2;i<=n;i++)
	cin>>a[i],sum[i]=sum[i-1]^a[i];
	for(ll i=1;i<=n;i++)
	if(sum[i]==k)
	ans++;
	while(l<=r)
	{
		ll mid=l+r>>1;
//  	cout<<"sum["<<l<<","<<r<<"]="<<(sum[r]|sum[l]^sum[l+1])<<endl;
		if(sum[r]-sum[l]+a[l+1]==k)
		ans++,l=mid+1;
		else
		r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
