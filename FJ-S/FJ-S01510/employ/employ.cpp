#include <bits/stdc++.h>
//#define int long long
#define rep(x, y, z) for(int x = (int)(y);x <= (int)(z);x++)
#define per(x, y, z) for(int x = (int)(y);x >= (int)(z);x--)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int N = 505, inf = 0x3f3f3f3f, mod = 1e9 + 7;
using namespace std;
int n, m, a[N], ans = 0;
string s;
bool vis[N];
void dfs(int id, int num, int cnt){
	if(id - 1 - cnt < a[num] && s[id] == '1') cnt++; 
	vis[num] = 1;
	if(id == n){
		if(cnt >= m) ans++;
		vis[num] = 0;
		return;
	}
	rep(i, 1, n) if(!vis[i]) dfs(id + 1, i, cnt);
	vis[num] = 0;
}
void sub1(){
	rep(i, 1, n) dfs(1, i, 0);
	printf("%d\n", ans);
}
void sub2(){
	rep(i, 1, n){
		if(s[i] == '0'){
			printf("0\n");
			return;
		}
	}
	rep(i, 1, n) if(a[i] == 0){
		printf("0\n");
		return;
	}
	int ans = 1;
	rep(i, 1, n) ans = 1ll * ans * i % mod;
	printf("%d\n", ans); 
}
void solve(){
	cin >> n >> m >> s;
	s = ' ' + s;
	rep(i, 1, n) scanf("%d", &a[i]);
	if(n == m) sub2();
	else if(n <= 18) sub1();
	else printf("0\n"); 
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int T = 1;
//	scanf("%d", &T);
	while(T--) solve();
	return 0;
}

