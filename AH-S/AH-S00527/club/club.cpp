#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct MEMBER {
	int fir, sec, thi;
	int a[4];
	
	void SORT() {
		if (a[fir] < a[sec]) swap(fir, sec);
		if (a[sec] < a[thi]) swap(sec, thi);
		if (a[fir] < a[sec]) swap(fir, sec);
		return;
	}
};

int T;
int n;
long long ans = 0;
vector<MEMBER> t[4];

bool COMP(MEMBER x, MEMBER y) {
	return x.a[x.fir] - x.a[x.sec] > y.a[y.fir] - y.a[y.sec];
}

void INIT() {
	t[1].clear();
	t[2].clear();
	t[3].clear();
	ans = 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while (T--) {
		INIT();
		
		cin >> n;
		
		MEMBER x;
		for (int i = 1; i <= n; ++i) {
			x.fir = 1, x.sec = 2, x.thi = 3;
			scanf("%d %d %d", &x.a[1], &x.a[2], &x.a[3]);
			x.SORT();
			t[x.fir].push_back(x);
		}
		
		for (int i = 1; i <= 3; ++i) {
			if ( (int) t[i].size() <= n / 2) {
				for (int j = 0; j < (int) t[i].size(); ++j) ans += t[i][j].a[i];
				continue;
			}
			sort(t[i].begin(), t[i].end(), COMP);
			for (int j = 0; j < n / 2; ++j) ans += t[i][j].a[i];
			for (int j = n / 2; j < (int) t[i].size(); ++j) ans += t[i][j].a[ t[i][j].sec ];
		}
		
		cout << ans << endl;
	}
	
}
