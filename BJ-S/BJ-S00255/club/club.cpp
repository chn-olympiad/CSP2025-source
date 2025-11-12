# include <bits/stdc++.h>

using namespace std;

const int max_n = 1e5 + 10;

int t;
int n;
int ans;
int cntx;
int cnty;
int cntz;

struct Member {
	int x, y, z;
} a[max_n];

vector <Member> x, y, z;

void Init() {
	ans = 0;
	x.clear();
	y.clear();
	z.clear();
	cntx = 0;
	cnty = 0;
	cntz = 0;
}

bool cmpx(Member x, Member y) {
	return min(x.x - x.y, x.x - x.z) <= min(y.x - y.y, y.x - y.z);
}

bool cmpy(Member x, Member y) {
	return min(x.y - x.x, x.y - x.z) <= min(y.y - y.x, y.y - y.z);
}

bool cmpz(Member x, Member y) {
	return min(x.z - x.x, x.z - x.y) <= min(y.z - y.x, y.z - y.y);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t --) {
		Init();
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
			if (a[i].x >= a[i].y && a[i].x >= a[i].z) {
				x.push_back(a[i]);
			}
			else if (a[i].y >= a[i].x && a[i].y >= a[i].z) {
				y.push_back(a[i]);
			}
			else if (a[i].z >= a[i].x && a[i].z >= a[i].y) {
				z.push_back(a[i]);
			}
		}
		sort(x.begin(), x.end(), cmpx);
		sort(y.begin(), y.end(), cmpy);
		sort(z.begin(), z.end(), cmpz);
		for (int i = x.size() - 1; (~ i) && cntx < (n >> 1); i --) {
			ans += x[i].x;
			x.pop_back();
			cntx ++;
		}
		for (int i = y.size() - 1; (~ i) && cnty < (n >> 1); i --) {
			ans += y[i].y;
			y.pop_back();
			cnty ++;
		}
		for (int i = z.size() - 1; (~ i) && cntz < (n >> 1); i --) {
			ans += z[i].z;
			z.pop_back();
			cntz ++;
		}
		for (int i = x.size() - 1; ~ i; i --) {
			if (cnty < (n >> 1) && x[i].y >= x[i].z) {
				ans += x[i].y;
				cnty ++;
			}
			else if (cntz < (n >> 1) && x[i].y < x[i].z) {
				ans += x[i].z;
				cntz ++;
			}
		}
		for (int i = y.size() - 1; ~ i; i --) {
			if (cntx < (n >> 1) && y[i].x >= y[i].z) {
				ans += y[i].x;
				cntx ++;
			}
			else if (cntz < (n >> 1) && y[i].x < y[i].z) {
				ans += y[i].z;
				cntz ++;
			}
		}
		for (int i = z.size() - 1; ~ i; i --) {
			if (cntx < (n >> 1) && z[i].x >= z[i].y) {
				ans += z[i].x;
				cntx ++;
			}
			else if (cnty < (n >> 1) && z[i].x < z[i].y) {
				ans += z[i].y;
				cnty ++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}