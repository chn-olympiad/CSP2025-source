#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],b[105],sum1,sum2;
int32_t main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	if(n==1&&m==1){
		printf("1 1");
		return 0;
	}
	else{
		sort(a+1,a+n*m+1);
		for(int i=1;i<=n*m;i++){
			if(a[i]==b[i]) sum1++;
			if(a[i]==b[n*m-i+1]) sum2++;
		}
		if(sum1==n*m){
			if(m%2!=0)   printf("%lld %lld",m,n);
			else printf("%lld 1",m);
		}
		else if(sum2==n*m) printf("1 1");
		else printf("%lld %lld",m,n);
		return 0;
	}
}
