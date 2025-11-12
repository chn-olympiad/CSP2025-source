#include<bits/stdc++.h>
#include<vector>
using namespace std;

const int mod = 998244353;
long long ez = 0;
long long unez = 0;
long long n, m;
long long hp[505];
long long text_list[505];
long long ans = 0;
long long _list[505];
long long _t = 0;
bool used[505];

bool check() {
	long long sum = 0;
	long long fall = 0;
	for (int i = 0; i < n; i++) {
		if (text_list[i]) {
			if (fall>=_list[i] || _list[i] == 0) {
				fall++;
			}
			else {
				fall = 0;
				sum++;
			}
		}
		else fall++;
	}
	return sum >= m;
}

void dfs(long long current_index, long long total) {
	if (current_index==total) {
		if (check()) {
			ans++;
			ans %= mod;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i]=true;
			_list[_t] = hp[i];
			_t++;
			dfs(current_index + 1, total);
			_t--;
			_list[_t] = 0;
			used[i]=false;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		text_list[i] = a - '0';
	}
	for (int i = 0; i < n; i++) {
		cin>>hp[i];
	}
	dfs(0, n);
	cout << ans % mod << "\n";
	return 0;
}
