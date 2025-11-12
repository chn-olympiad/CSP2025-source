#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>
inline void read(T &x) {
	x = 0;
	bool flag = 0;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') flag = !flag;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}

	if(flag)x = -x;
}

template<typename T>
inline void write(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}

constexpr ll mod = 998244353;
ll ans = 0;

void dfs(vector<int> &a, int n, int dep, vector<int> get) {
	if(dep == n + 1) {
		ll sum = 0;
		ll maxn = 0;
		for(int i = 0; i < get.size(); i++) {
			sum += get[i];
			if(get[i] > maxn) {
				maxn = get[i];
			}
		}
		if(sum > 2 * maxn) {
			ans++;
			ans %= mod;
		}
		return;
	} 
	dfs(a, n, dep + 1, get);
	get.push_back(a[dep]);
	dfs(a, n, dep + 1, get);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n;
	read(n);
	vector<int> a(n + 1);
	
	for(int i = 1; i <= n; i++) {
		read(a[i]);
	} 
	if(n > 26) {
		write(0);
		return 0;
	}
	
	vector<int> get;
	dfs(a, n, 1, get);
	write(ans);
	
	return 0;
}


