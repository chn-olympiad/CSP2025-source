#include<bits/stdc++.h>
using namespace std;
long long a[50005],b[50005],c[50005],d[50005],n,sum=1,ma,mi=10000,mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sum=(sum*2)%mod;
	sum=(sum+mod-(n*n+n)/2-1)%mod;
	printf("%lld",sum);
	return 0;
} 
