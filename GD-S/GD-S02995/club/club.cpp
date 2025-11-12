#include<bits/stdc++.h>
#define lo long long
using namespace std;
lo T,a1[100010],a2[100010],a3[100010],n,ans;
void dfs(lo wei,lo sum,lo n1,lo n2,lo n3){
	if(wei<=n){
		if(n1<n/2) dfs(wei+1,sum+a1[wei],n1+1,n2,n3);
		if(n2<n/2) dfs(wei+1,sum+a2[wei],n1,n2+1,n3);
		if(n3<n/2) dfs(wei+1,sum+a3[wei],n1,n2,n3+1);
	}else ans=max(ans,sum);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans=0;
		scanf("%lld",&n);
		for(lo i=1;i<=n;i++) scanf("%lld%lld%lld",&a1[i],&a2[i],&a3[i]);
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
