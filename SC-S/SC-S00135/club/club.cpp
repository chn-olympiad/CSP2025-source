#include<bits/stdc++.h>
using namespace std;
#define nmax 100007
#define int long long
int t;

int n;
struct node {
	int x, y, z;
	int iid;
} a[nmax], b[nmax], c[nmax];

bool cmp1(const node& x, const node& y) {
	return x.x > y.x;
}

bool cmp2(const node& x, const node& y) {
	return x.y > y.y;
}

bool cmp3(const node& x, const node& y) {
	return x.z > y.z;
}

int mapping1[nmax]; // a(old)[i] -> a(new)[mapping1[i]]
int mapping2[nmax];
int mapping3[nmax];
int cnt[10]; // 每一组的人数
int solve() {
	sort(a + 1, a + n + 1, cmp1);
	sort(b + 1, b + n + 1, cmp2);
	sort(c + 1, c + n + 1, cmp3);

	for (int i = 1; i <= n; i++) {
		mapping1[a[i].iid] = i;
	}

	for (int i = 1; i <= n; i++) {
		mapping2[b[i].iid] = i;
	}

	for (int i = 1; i <= n; i++) {
		mapping3[c[i].iid] = i;
	}

	int res = 0;

	int tot = n / 2;

	for (int i = 1; i <= n; i++) {
		int mp1 = mapping1[i];
		int mp2 = mapping2[i];
		int mp3 = mapping3[i];

		vector<pair<int, int> > mps = {{mp1, 1}, {mp2, 2}, {mp3, 3}};
		sort(mps.begin(), mps.end());

		for (int i = 0; i < (int)mps.size(); i++) {
			int mp = mps[i].first;
			int cnts = mps[i].second;

			if (cnt[cnts] <= tot) {
				cnt[cnts]++;

				switch (cnts) {
					case 1: {
						res += a[mp].x;
						break;
					}

					case 2: {
						res += b[mp].y;
						break;
					}

					case 3: {
						res += c[mp].z;
						break;
					}
				}

				break;
			}
		}
	}

	return res;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].iid = i;
			b[i] = c[i] = a[i];
		}

		cout << solve() << endl;
	}

	return 0;
}

/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
>>>
18
*/