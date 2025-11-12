#include<bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e5+5;
int T, n;
LL ans, a[N][4];
struct student {
	int p, max1, max2;
	
	bool friend operator < (student x, student y) {
		if(a[x.p][x.max1]-a[x.p][x.max2] != a[y.p][y.max1]-a[y.p][y.max2])return a[x.p][x.max1]-a[x.p][x.max2] < a[y.p][y.max1]-a[y.p][y.max2];
		else if(a[x.p][x.max1] != a[y.p][y.max1])return a[x.p][x.max1] < a[y.p][y.max1];
		else if(a[x.p][x.max2] != a[y.p][y.max2])return a[x.p][x.max2] > a[y.p][y.max2];
		else return x.p < y.p;
	}
};
multiset<student> st[4];

void Main() {
	cin >> n;
	ans = 0;
	st[1].clear();st[2].clear();st[3].clear();
	for(int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int max1 = 0, max2 = 0;
		for(int j = 1; j <= 3; j++) {
			if(a[i][j] >= a[i][max1]) max2 = max1, max1 = j;
			else if(a[i][j] >= a[i][max2]) max2 = j;
		}
		//printf("%d:%d %d\n", i, max1, max2);
		if(st[max1].size() >= n/2) {
			student u = *st[max1].begin();
			if(a[i][max1]-a[u.p][u.max1]+a[u.p][u.max2] > a[i][max2]) {
				st[max1].erase(st[max1].begin());
				st[u.max2].insert(u);
				st[max1].insert({i, max1, max2});
				ans += a[i][max1]-a[u.p][u.max1]+a[u.p][u.max2];
				//printf("swap %d by %d(%d %d)\n", u.p, i, a[i][max1]-a[u.p][u.max1]+a[u.p][u.max2]);
			}
			else {
				st[max2].insert({i, max1, max2});
				ans += a[i][max2];
				//printf("%d can't win %d\n", i, u.p);
			}
		}
		else {
			st[max1].insert({i, max1, max2});
			ans += a[i][max1];
			//printf("%d is happy\n", i);
		}
	}
//	for(int i = 1; i <= 3; i++) {
//		printf("%d:", i);
//		while(!st[i].empty()) {
//			printf("%d ", (*st[i].begin()).p);
//			st[i].erase(st[i].begin());
//		}
//		puts("");
//	}
	cout << ans << "\n";
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> T;
	while(T--) {
		Main();
	}
	
	return 0;
}
