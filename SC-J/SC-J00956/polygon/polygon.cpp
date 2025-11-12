#include<bits/stdc++.h>
using namespace std;
const long long inf=998244353;
int n,a[5010],b,g;
long long ans,jc[5010];
void count(int m){
	jc[0]=1;
	for(int i=1;i<=m;i++){
		jc[i]=jc[i-1]*i%inf;
	}
	for(int i=3;i<=n;i++){
		ans+=((jc[n]%inf)/jc[i]/jc[n-i])%inf;
	}
	return;
}
void dfs(int l,int p){
	if(l>n)return;
	b+=a[l];
	if(p>=2&&b>a[l]*2){
		ans++;
		ans%=inf;
	}
	dfs(l+1,p+1);
	b-=a[l];
	dfs(l+1,p);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)g=1;
	}
	if(g==0){
		count(n);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
} 