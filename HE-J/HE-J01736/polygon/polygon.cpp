#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
int n,a[5005],sum,maxn=INT_MIN;
int32_t main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(n==3){
		if(sum>maxn*2) printf("1");
		else printf("0");
		return 0;
	}
	else printf("0");
	return 0;
}
