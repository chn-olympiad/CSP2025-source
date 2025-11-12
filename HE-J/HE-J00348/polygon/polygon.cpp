#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5500,mod=998244353;
int n,a[N];
int ans=0;
void dfs(int k,int x,int y,int sum){
	if(k>y){
		ans++;
		ans%=mod;
	}
	for(int i=1;i<sum-x;i++){
		dfs(k+a[x+i],x+i,y,sum);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(0,0,a[i],i);
	}
	printf("%lld",ans);
	return 0;
}
