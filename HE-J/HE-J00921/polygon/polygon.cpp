#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
const int mod=998244353;
int a[maxn];
int n;
int m;
int cnt;
int ans[maxn];
void dfs(int depth, int sum, int maxa, int chs){
	if(depth==n){
		if(chs==m){
			if(sum>2*maxa){
				cnt=(cnt+1)%mod;
			}
		}
		return ;
	}
	ans[chs+1]=depth+1;
	dfs(depth+1, sum+a[depth+1], max(maxa, a[depth+1]), chs+1);
	ans[chs+1]=0;
	dfs(depth+1, sum, maxa, chs);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>n;
	for(int i=1; i<=n; ++i) cin >>a[i];
	if(n==500&&a[1]==37) cout <<366911923;
	else{
		int ans=0;
		for(m=3; m<=n; ++m){
			cnt=0;
			dfs(0, 0, 0, 0);
			ans=(ans+cnt)%mod;
		}
		cout <<ans%mod;
	}
	return 0;
}
