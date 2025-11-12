#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define x first
#define y second
#define vec vector
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define MAXN 1000005

template <typename T> void read (T &x) {
	x = 0; T f = 1; char ch = getchar ();
	while (!isdigit (ch)) { if (ch == '-') f = -1; ch = getchar (); }
	while (isdigit (ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar ();
	x *= f;
}

template <typename T, typename ...Arp> void read (T &x, Arp & ...arp) {
	read (x), read (arp...);
}

string s;
int num[10];

signed main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	cin >> s;
	
	for (const auto & ch : s) {
		if (isdigit (ch))
			++num[ch - '0'];
	}
	
	for (int i = 9; ~i; --i)
		while (num[i]--)
			putchar (i + '0');
			
	putchar ('\n');
	return 0;
}
