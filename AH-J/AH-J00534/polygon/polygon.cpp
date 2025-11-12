#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n,a[5010],cnt;
long long lower(long long l,long long r,long long x){
	while(l<r){
		long long mid=(l+r)>>1;
		if(a[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}
void dfs(long long cur,long long h,long long p){
	if(cur>=3&&h>a[p]) cnt=(cnt+lower(p+1,n+1,h)-p-1)%Mod;
	if(p>=n-1) return;
	for(long long i=p+1;i<n;i++) dfs(cur+1,h+a[i],i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(a[n]==1) cnt=(n-1)*(n-2)/2%Mod;
	else dfs(1,0,0);
	printf("%lld",cnt);
	return 0;
}
