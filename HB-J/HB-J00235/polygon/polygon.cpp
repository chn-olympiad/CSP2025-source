#include<bits/stdc++.h>
using namespace std;
int n,a[5005],flag=1;
long long ans;
void dfs(int cnt,long long sum,int mx,int st){
	if(cnt>2&&sum>mx*2) ans=(ans+1)%998244353;
	if(st==n) return;
	for(int i=st+1;i<=n;++i)
		dfs(cnt+1,sum+a[i],max(mx,a[i]),i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]!=1) flag=0;
	}
	if(flag){
		for(int i=3;i<=n;++i){
			int x=1;
			for(int j=n;j>n-i;--j) x=x*j%998244353;
			for(int j=i;j;--j) x/=j;
			ans=(ans+x)%998244353;
		}
	}
	else dfs(0,0,0,0);
	printf("%lld",ans);
	return 0;
}
