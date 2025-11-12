#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
int n;
int l[5010];
ll cnt = 0;
void dfs(int x, int statue, ll s, int maxn){
	if(x > n) return;
	if(statue==1){
		int tmp = maxn;
		if(l[x]>maxn) tmp = l[x];
		if(s+l[x]>2*tmp) cnt = (cnt+1)%MOD;
		dfs(x+1, 0, s+l[x], tmp);
		dfs(x+1, 1, s+l[x], tmp);
	}
	else{
		dfs(x+1, 0, s, maxn);
		dfs(x+1, 1, s, maxn);
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &l[i]);
	dfs(1, 0, 0, 0);
	dfs(1, 1, 0, 0);
	
	printf("%lld", cnt%MOD);
	return 0;
}
