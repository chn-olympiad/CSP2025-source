#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int N = 501, mod = 998244353;

int n, m, a[N];
string s;
int c[N];
bool vis[N];
LL ans = 0, jc[N], ly[N];

void dfs(int now, int cnt){
	if(cnt == n){
		if(n - now >= m){
			ans = (ans + 1) % mod; 
		}
		return;
	}
	if(m > n - now) return;
	if(cnt - now >= m){
		ans = (jc[n - cnt] + ans) % mod;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		int add = 0;
		if(c[i] <= now  || !a[cnt + 1]) add = 1;
		dfs(now + add, cnt + 1);
		vis[i] = 0;
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> s;
	jc[0] = 1;
	for(int i = 1; i <= n; i++){
		jc[i] = (jc[i - 1] * i) % mod;
	}
	bool ok = 1;
	for(int i = 1; i <= n; i++){
		a[i] = s[i - 1] - '0';
		if(!a[i]) ok = 0;
	}
	c[0] = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}
