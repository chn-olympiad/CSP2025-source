#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=3e6+11451,MAX=3948576;
ll n,k,a[N],sum[N],ans=0;
ll mx[MAX];
ll f[N],mx_f[N];
/*
4 2
2 1 0 3

2 

4 0
2 1 0 3

1

*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%lld%lld",&n,&k);
	
	for(ll i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		sum[i]=(sum[i-1]^a[i]);
		
//		if(mi[sum[i]]==0) mi[sum[i]]=i;
	}
	
//	for(ll r=n;r>=1;)
//	{
//		ll suml_1=(sum[r]^k);
//		if(mi[suml_1]<r) {
//			ll l=r;
//			for(;l>=1;l--) {
//				if((sum[l-1]^sum[r])==k) break;
//			}
//			r=l-1;
//		}
//		else r--;
//	}

	for(ll i=1;i<=n;i++)
	{
		mx[sum[i]]=i;
		
		ll suml_1=(sum[i]^k);
		if((mx[suml_1]!=0)||(suml_1==0))
		{
			f[i]=mx_f[mx[suml_1]]+1;
		}
		mx_f[i]=max(mx_f[i-1],f[i]); 
	}
	
	printf("%lld",mx_f[n]);
	
	return 0;
}