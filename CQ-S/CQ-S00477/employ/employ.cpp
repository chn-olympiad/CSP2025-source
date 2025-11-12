#include<bits/stdc++.h>
#define N 512
#define int long long
#define mod 998244353
using namespace std ;
int n , m , c[N] , ans=0 , jie[N] ;
char s[N] ;
bool used[N] ;
void dfs(int dep,int giveup,int sum){
	if(n-giveup<m) return ;
	if(dep>n||sum==m){
		ans += jie[n-dep+1] ;
		ans %= mod ;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1 ;
			if(giveup>=c[i]||s[dep]=='0') dfs(dep+1,giveup+1,sum) ;
			else dfs(dep+1,giveup,sum+1) ;
			used[i]=0 ;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin) ;
	freopen("employ.out","w",stdout) ;
	cin >> n >> m ;
	jie[0]=1 ;
	for(int i=1;i<=n;i++) jie[i] = jie[i-1]*i%mod ;
	scanf("%s",s+1) ;
	for(int i=1;i<=n;i++) scanf("%lld",c+i) ;
	dfs(1,0,0) ;
	cout << ans ;
	return 0 ;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
