#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w",stdout);
	
	int n, m, p = 0; cin >> n >> m;
	string s; cin >> s;
	for (int i = 1; i <= n; i++)
	{
			int c; cin >> c;
			if(c == 0)p++;
	}
	int ccc = n - p;
	
	int gent = 1;
	
	for (int i = 1; i <= ccc; i++) {
		gent *= i;
		gent %= 998244353;
	}
	
	cout << gent << '\n';
}
