#include <bits/stdc++.h>
using namespace std;
#define prt printf
#define pb push_back
#define pp pop_back
//#define _x first
//#define _y second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 1e5 + 7, INF = 0x3f3f3f3f;

void put(ll x, char el = '\n') {
	prt("%lld", x);
	putchar(el);
}

vector<char> v;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			v.pb(s[i]);
		}
	}
	sort(v.begin(), v.end(), greater<char>());
	for (auto i : v) {
		putchar(i);
	}
	putchar('\n');
//	fclose(stdin); fclose (stdout);
	return 0;
}
