#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
unsigned long long C(int m){
	m=min(m,n-m);
	unsigned long long pi1=1,pi2=1;
	for (int i=n,j=m;j>=1;i--,j--){
		pi1*=i,pi2*=j;
		unsigned long long p=__gcd(pi1,pi2);
		pi1/=p,pi2/=p;
	}
	return pi1/pi2%998244353;
}
void solve(){
	long long ans=0;
	for (int i=3;i<=n;i++){
		ans+=C(i);
		ans%=998244353;
	}
	printf("%lld\n",ans);
}
int ans[5010];
long long cnt;
void dfs(int p,int k){
	if (p==n){
		int sum=0,maxx=0;
		for (int i=1;i<=k;i++){
			sum+=a[ans[i]];
			maxx=max(maxx,a[ans[i]]);
		}
		if (k>=3&&sum>maxx*2){
			cnt++;
			cnt%=998244353;
		}
		return ;
	}
	ans[k+1]=p+1;
	dfs(p+1,k+1);
	dfs(p+1,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int flg=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]>1){
			flg=0;
		}
	}
	if (flg){
		solve();
	}
	else{
		dfs(0,0);
		printf("%lld",cnt);
	}
	return 0;
}
