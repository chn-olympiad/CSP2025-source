#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5,MOD=998244353;
int n,a[MAXN],ans,max1;
void dfs(int x,long long s,long long mx,int num){
	if(x>n){
		if(s>mx*2){
			ans++;
			ans%=MOD;
		}
		return ;
	}
	if(num+n-x+1<3){
		return ;
	}
	dfs(x+1,s,mx,num);
	long long nmax=max(mx,1LL*a[x]);
	dfs(x+1,s+a[x],nmax,num+1);
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		max1=max(max1,a[i]);
	}
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}
