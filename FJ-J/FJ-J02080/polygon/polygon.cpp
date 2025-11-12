#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n; ll ans;
int a[5005],pre[5005];
int dfs(int s,int k,int sum){
	if(k==s){
		if(sum>a[s]) return 1;
		else return 0;
	}
	if(pre[s-1]-pre[k-1]+sum<=a[s]) return 0;
	return dfs(s,k+1,sum+a[k])+dfs(s,k+1,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=3;i<=n;i++){
		ans+=dfs(i,1,0);
		ans%=mod;
	}
	printf("%lld\n",ans%mod);
	return 0;
}
