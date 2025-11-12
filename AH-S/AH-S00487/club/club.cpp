#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t,n,a[300010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		for(LL i=1;i<=3*n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+3*n+1);LL sum=0;
		for(LL i=3*n;i>3*n-n/2;i--) sum+=a[i];
		printf("%lld",sum);
	}
	return 0;
}
