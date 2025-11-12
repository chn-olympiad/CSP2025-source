#include <bits/stdc++.h>
using namespace std;
const int maxn=5010;
long long ans=0,p=998244353;
int s[maxn],a[maxn],n;
long long jc(int m){
	long long res=1;
	for(int i=2;i<=m;i++) res*=i%p;
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) printf("1");
		else printf("0");
		return 0;
	}
	long long len=jc(n);
	for(int i=3;i<=n;i++){
		ans+=len/(jc(i)*jc(n-i));
	}
	printf("%lld",ans);
	return 0;
}