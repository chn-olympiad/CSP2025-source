#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n,a[N];
long long ans = 0,mod = 998244353;
void dfs(int dep,int cnt,int maxn,int tot){ 
	if(cnt >= 3 && tot > max(maxn,a[dep])*2) ans = (ans+1) % mod;
	if(dep > n) return ;
	if(n-dep+1 + cnt < 3) return ;
	dfs(dep+1,cnt+1,max(maxn,a[dep]),tot+a[dep]);
	dfs(dep+1,cnt,maxn,tot);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
