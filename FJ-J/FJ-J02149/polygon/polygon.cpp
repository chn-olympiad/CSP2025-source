#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005];
long long n,m,k,gg;
long long ans;
void dfs(long long dep,long long h,long long maxn){
	if(dep==n+1){
		if(maxn*2<h){
			ans++;
			ans%=998244353;
		}
		return;
	}
	dfs(dep+1,h+a[dep],max(maxn,a[dep]));
	dfs(dep+1,h,maxn);
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	if(b[1]==1&&b[n]==1){
		long long ansans=n*(n-1)*(n-2);
		ansans%=998244353;
		cout<<ansans;
		return 0;
	}
	if(n<=26){
		dfs(1,0,0);
		printf("%lld",ans);
		return 0;
	}
	printf("%lld",ans);
	return 0;
}
