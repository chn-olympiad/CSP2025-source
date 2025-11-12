#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,now=3,a[5010];
bool f[5010];
long long ans;
bool check(int mintot,int maxn){
	return mintot>2*maxn;
}
void dfs(int mintot,int last,int dep){
	if(dep==now){
		ans+=check(mintot,a[last]);
		ans%=MOD;
		return;
	}
	for(int i=last+1;i<=n;i++){
		dfs(mintot+a[i],i,dep+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	while(now<=n){
		dfs(0,0,0);
		now++;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}