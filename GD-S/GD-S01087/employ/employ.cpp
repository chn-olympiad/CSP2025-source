#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 520;
const int mod = 998244353;

int n, m, ans, c[N];
bool vis[N];
string s;

vector<int> vec;
void dfs(int x) {
	if (x == n + 1) {
		int now = 0, sum = 0, res = 0;
		for (auto i : vec) {
			if (sum >= c[i] || s[now] == '0') sum++;
			else res++;
			now++;
		}
		
		ans += (res >= m);
		return ;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1, vec.push_back(i);
			dfs(x + 1);
			vis[i] = 0, vec.pop_back();
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	cin >> s;
	
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	
	dfs(1);
	return 0;
}
