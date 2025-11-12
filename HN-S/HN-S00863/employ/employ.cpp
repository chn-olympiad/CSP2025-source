#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 500;

int T, n, ans, m;
int c[N], flag[N];
string s;
vector<int> v;

int Check() {
	int cnt = 0, res = 0;
//	cout << "---------\n";
	for (int i = 1; i <= n; i++) {
//		cout << v[i] << ' ' << c[v[i]] << ' ' << s[i] << ' ' << cnt << ' ' << res << '\n';
		if (cnt >= c[v[i]]) {
			cnt++;
//			cout << "1\n";
			continue;
		}
		if (s[i] == '0') {
			cnt++;
//			cout << "2\n";
		} else {
			res++;
		}
	}
//	cout << '\n';
//	cout <<res << ' ' << m << '\n';
	return res >= m;
}

void DFS(int x) {
	if (x == n + 1) {
		ans += Check();
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			flag[i] = 1;
			v.push_back(i);
			DFS(x + 1);
			v.pop_back();
			flag[i] = 0;
		} 
	}
	return ;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = '#' + s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i]; 
	}
	v.push_back(0);
	DFS(1);
	cout << ans; 
	return 0;
}
/**
*/
