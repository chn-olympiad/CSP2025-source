#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=5005,mod=998244353;
int n,a[N];
ll ans;
int f=1;
ll c[N][N];
void dfs(int u,ll cnt,int v){
	if(u==v){
		if(cnt>a[v]) ans=(ans+1)%mod;
		return;
	}
	for(int i=u+1;i<=v;i++){
		dfs(i,cnt+a[u],v);
	}
}
void init(){
	c[1][1]=1;
	for(int i=2;i<=5003;i++){
		for(int j=1;j<=5003;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) f=0;
	}
	if(f){
		ans=0;
		init();
		for(int i=3;i<=n;i++){
			ans+=c[n+1][i+1];
		}
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			dfs(j,0,i);
		}
	}
	printf("%lld",ans);
	return 0;
}


