#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define MAXN 1000005
#define MAXM 100005
#define pii pair<int, int>

int a[MAXN];
int cnt = 0;

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	char curr = '\0';
	while (cin >> curr) {
		if ('0' <= curr && curr <= '9') {
			a[++cnt] = curr - '0';
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	for (int i = 1; i <= cnt; ++i)
		cout << a[i];
	return 0;
}