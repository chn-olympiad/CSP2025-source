#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define Pii pair<int, int>
#define fst first
#define snd second
#define pb push_back
#define endl '\n'

//#define LOCALGDB

LL a[100010][4], p;
vector<int> v[4];

bool cmp(int A, int B) {
	return  min(a[A][p] - a[A][p % 3 + 1], a[A][p] - a[A][(p + 1) % 3 + 1]) < \
			min(a[B][p] - a[B][p % 3 + 1], a[B][p] - a[B][(p + 1) % 3 + 1]);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		p = 0;
		v[1].clear();
		v[2].clear();
		v[3].clear();
		int n;
		LL sum = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) v[1].pb(i), sum += a[i][1];
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) v[2].pb(i), sum += a[i][2];
			else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) v[3].pb(i), sum += a[i][3];
		}
		for (int i = 1; i <= 3; ++i) {
			if ((int)v[i].size() > n / 2) {
				p = i;
				break;
			}
		}
		if (!p) {
			cout << sum << endl;
		} else {
			sort(v[p].begin(), v[p].end(), cmp);
			for (int i = 0; i < (int)v[p].size() - n / 2; ++i) {
				sum -= min(a[v[p][i]][p] - a[v[p][i]][p % 3 + 1], a[v[p][i]][p] - a[v[p][i]][(p + 1) % 3 + 1]);
			}
			cout << sum << endl;
		}
	}
	fflush(stdout);
	return 0;
}

