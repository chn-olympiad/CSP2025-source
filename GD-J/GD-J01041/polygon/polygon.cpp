#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
int n,a[N];
ll mod=998244353,ans,c[N][N];
bool chk(int x,int y){
	if(x>2*y) return true;
	return false;
}
void dfs(int x,int sum,int mx,int t){
	if(x>n){
		if(chk(sum,mx)&&t>=3){
			ans=(ans+1)%mod;
		}
		return;
	}
	dfs(x+1,sum+a[x],a[x],t+1);
	dfs(x+1,sum,mx,t);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(a[n]==1){
		for(int i=0;i<=n;i++){
			c[i][0]=1;
			c[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
		}
		for(int i=3;i<=n;i++) ans=(ans+c[n][i])%mod;
		printf("%lld",ans);
		return 0;
	}
	dfs(1,0,0,0);
	printf("%lld",ans);
}
