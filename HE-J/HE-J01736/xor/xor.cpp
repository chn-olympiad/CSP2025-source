#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],sum1,sum2,ans;
int32_t main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==1) sum1++;
		if(a[i]==0) sum2++;
	}
	if(sum1==n){
		for(int i=1;i<=n;i++)
			ans^=1;
		printf("%lld",ans);
		return 0;
	}
	else if(sum1+sum2==n){
		sum1/=2; sum2/=2;
		for(int i=1;i<=sum1;i++) ans^=1;
		for(int i=1;i<=sum2;i++) ans^=0;
		printf("%lld",ans);
		return 0;
	}
	printf("1");
	return 0;
}
