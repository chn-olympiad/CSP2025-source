//GZ-S00040 贵阳市白云区华师一学校 冯子尧 
#include <bits/stdc++.h>

#define upp(a, x, y) for (int a = x; a <= y; a ++)
#define dww(a, x, y) for (int a = x; a >= y; a --)
#define lowbit(x) x & -x
#define pb(x) push_back(x)
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 1e5 + 10;

int n;
LL a[N][4];
LL sum;

vector<int> x, y, z;

LL rmax(LL a, LL b, LL c) {
	if ((a - b) * (a - c) <= 0) return a;
	if ((b - a) * (b - c) <= 0) return b;
	return c; 
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	
	cin >> T;
	while (T --) {
		sum = 0;
		x.clear(), y.clear(), z.clear();
		
		cin >> n;
		upp (i, 1, n) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int t = max(a[i][1], max(a[i][2], a[i][3]));
			if (t == a[i][1]) x.pb(i);
			else if (t == a[i][2]) y.pb(i);
			else z.pb(i);
			sum += t;
		}
		if (x.size() <= n / 2 && y.size() <= n / 2 && z.size() <= n / 2) {
			cout << sum << '\n';
			continue;
		}
		vector<LL> ls;
		int m;
		if (x.size() > n / 2) {
			m = x.size();
			upp (i, 0, m - 1) {
				LL t1 = a[x[i]][1], t2 = a[x[i]][2], t3 = a[x[i]][3];
				ls.pb(max(t1, max(t2, t3)) - rmax(t1, t2, t3));
			}
		}
		else if (y.size() > n / 2) {
			m = y.size();
			upp (i, 0, m - 1) {
				LL t1 = a[y[i]][1], t2 = a[y[i]][2], t3 = a[y[i]][3];
				ls.pb(max(t1, max(t2, t3)) - rmax(t1, t2, t3));
			}
		}
		else {
			m = z.size();
			upp (i, 0, m - 1) {
				LL t1 = a[z[i]][1], t2 = a[z[i]][2], t3 = a[z[i]][3];
				ls.pb(max(t1, max(t2, t3)) - rmax(t1, t2, t3));
			}
		}
		sort(ls.begin(), ls.end());
		upp (i, 0, m - n / 2 - 1) sum -= ls[i];
		cout << sum << '\n';
	}
	return 0;
}
