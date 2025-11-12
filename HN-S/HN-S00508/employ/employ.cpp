#include<bits/stdc++.h>
#define RD read()
#define rep(i, x, y) for(int i = x;i <= y;++ i)
using namespace std;
int read(){
	int x = 0, f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0';ch = getchar();}
	return x * f;
}
int n, m, a[505];
long long ans;
char s[505];
int c[505];
bool vis[505];
bool check(){
	int now = 0, res = 0;
	rep(i, 1, n){
		if(s[i] == '0' || now >= c[a[i]]) ++ now, ++ res;
		if(n - res < m) return 0;
	}
	return 1;
}
void dfs(int k){
	if(k > n){
		ans += check();
		ans %= 998244353;
		return;
	}
	rep(i, 1, n){
		if(vis[i]) continue;
		vis[i] = 1;
		a[k] = i;
		dfs(k + 1);
		vis[i] = 0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = RD;m = RD;
	cin >> s + 1;
	long long sum = 0;
	rep(i, 1, n) sum += s[i] - '0';
	if(sum < m){
		printf("0");
		return 0;
	}
	rep(i, 1, n) c[i] = RD;
	int p = 0;
	if(sum == n){
		sum = 1;
		rep(i, 1, n){
			if(!c[i]) ++ p;
		}
		sort(c + 1, c + n +1);
		rep(i, 1, n){
			if(!c[i]) continue;
			sum = sum * (min(p, c[i]) + i - p) % 998244353;
		}
		printf("%lld", sum);
		return 0;
	}
	dfs(1);
	printf("%lld", ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
