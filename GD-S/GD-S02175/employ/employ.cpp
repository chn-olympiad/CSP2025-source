#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
using namespace std;

const int N=20;
int n, m, c[N], p[N];
string s;

int ans;

bool check () {
	int now=0, res=0, g=0;
	for (int i=1; i <= n; i++) {
		if (s[i-1] == '0') {g++; continue;} 
		if (g >= c[p[i]]) {g++; continue;}
		res++;
	}
	return (res >= m);
}

int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> m >> s;
	for (int i=1; i <= n; i++) cin >> c[i];
	if (n <= 10) {
		for (int i=1; i <= n; i++) p[i]=i;
		ans=check ();
		while (next_permutation (p+1, p+n+1) ) {
			ans+=check (); 
		}
		cout << ans;
	}
	return 0;
}

