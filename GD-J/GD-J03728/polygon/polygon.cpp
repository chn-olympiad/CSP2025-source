#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],d[25000005],i,j,m,s,ans,mo=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1),d[0]=1;
	if(a[1]==a[n]){
		s=n,m=1;
		while(s--)m*=2,m%=mo;
		printf("%lld",(m+mo+mo+mo-1-n*(n-1)/2%mo-n%mo)%mo);
		return 0;
	}
	for(i=1;i<=n;i++){
		s+=a[i];
		for(j=s;j>a[i];j--)ans+=d[j],ans%=mo,d[j]+=d[j-a[i]],d[j]%=mo;
		d[a[i]]+=d[0],d[a[i]]%=mo;
	}
	printf("%lld",ans);
	return 0;
}
