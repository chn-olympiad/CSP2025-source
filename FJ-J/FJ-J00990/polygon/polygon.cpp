#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=998244353;
int n,a[N],ans;
int maxn;
bool vis[N];
void dfs(int x,int sum){
	if(x>n){
		if(sum>2*maxn) ans++;
		ans%=MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int ym=maxn;
		maxn=max(maxn,a[i]);
		vis[i]=1;
		dfs(x+1,sum+a[i]);
		vis[i]=0;
		maxn=ym;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<3) return printf("0"),0;
	else if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) printf("1");
		else printf("0");
		return 0;
	}
	dfs(3,0);
	printf("%d",ans%MOD/2);
	return 0;
}
