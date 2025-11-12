#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define N (int)(5e2 + 5)
#define M (int)(1e6 + 5)
#define mod 998244353
#define inf (int)(2e9)
#define qwe(i, l, r) for(int i = l; i <= r; i++)
#define ewq(i, r, l) for(int i = r; i >= l; i--)
#define P pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int T = 1;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		f = ch =='-' ? -f : f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n, m, ans;
char S[N];
int s[N], c[N];
bool flag[N];
void dfs(int x, int now){
	if(now > n - m) return;
	if(x == n + 1){
		(ans += 1) %= mod;
		return;
	}
	qwe(i, 1, n){
		if(!flag[i]){
			flag[i] = 1;
			if(S[x] == '0' || now >= c[i]) dfs(x + 1, now + 1);
			else dfs(x + 1, now);
			flag[i] = 0;
		}
	}
}
void solve(){
	n = read(), m = read();
	scanf("%s", S + 1);
	qwe(i, 1, n) c[i] = read();
	dfs(1, 0);
	printf("%d", ans);
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	T = read();
	while(T--) solve();
	return 0;
}
/*

Makka pakka :D
*/

