#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5005;
constexpr long long mod = 998244353;

int n, a[N];
bool b[N];
long long ans;

void dfs(int x, long long sumn, int maxn, int st){
	if(x >= 3 && sumn > (1LL * 2 * maxn)){
		ans++;
		if(ans > mod) ans -= mod;
	}
	if(x > n) return;
	for(int i = st + 1; i < n; i++){
		if(b[i]) continue;
		b[i] = true;
		dfs(x + 1, sumn + a[i], max(maxn, a[i]), i);
		b[i] = false;
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	dfs(0, 0, 0, -1);
	cout << ans;
}
