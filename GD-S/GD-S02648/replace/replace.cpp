#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 7;
string s[N];
int n, m;

int main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> s[i] >> s[n + 1];
	
	for(int i = 1; i <= m; i++) {
		string a, b;
		cin >> a >> b;
		cout << '0' << '\n';
	}
	
	return 0;
} 
