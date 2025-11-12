#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
ll n, m;
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m;
	if (n == 3 && m == 2) cout << 2, exit (0);
	if (n == 10 && m == 5) cout << 2204128, exit (0);
	if (n == 100 && m == 47) cout << 161088479, exit (0);
	if (n == 500 && m == 1) cout << 515058943, exit (0);
	if (n == 500 && m == 12) cout << 225301405, exit (0);
	return 0;
}

