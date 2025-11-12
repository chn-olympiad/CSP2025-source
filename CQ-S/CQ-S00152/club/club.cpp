#include<bits/stdc++.h>
#define ll long long
#define fast_running ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
const int N = 1e5 + 5;
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
ll n, ans;
struct club{
	int a, b, c;
}l[N];
bool cmpx(int x, int y) {
	return l[x].a - max(l[x].b, l[x].c) < l[y].a - max(l[y].b, l[y].c);
}
bool cmpy(int x, int y) {
	return l[x].b - max(l[x].a, l[x].c) < l[y].b - max(l[y].a, l[y].c);
}
bool cmpz(int x, int y) {
	return l[x].c - max(l[x].b, l[x].a) < l[y].c - max(l[y].b, l[y].a);
}
int main() {
	fast_running;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		ans = 0;
		vector<int> x, y, z;
		for (int i = 1; i <= n; i++) {
			cin >> l[i].a >> l[i].b >> l[i].c;
			if (l[i].a >= l[i].b && l[i].a >= l[i].c) {
				x.push_back(i);
				ans += l[i].a;
			}else if (l[i].b >= l[i].a && l[i].b >= l[i].c) {
				y.push_back(i);
				ans += l[i].b;
			}else if (l[i].c >= l[i].b && l[i].c >= l[i].a) {
				z.push_back(i);
				ans += l[i].c;
			}
		}
		if (x.size() > (n / 2)) {
			sort(x.begin(), x.end(), cmpx);
			int flag = x.size() - (n / 2);
			for (int i = 0; i < flag; i++) {
				ans -= l[x[i]].a - max(l[x[i]].b, l[x[i]].c);
			}
		}else if (y.size() > (n / 2)) {
			sort(y.begin(), y.end(), cmpy);
			int flag = y.size() - (n / 2);
			for (int i = 0; i < flag; i++) {
				ans -= l[y[i]].b - max(l[y[i]].a, l[y[i]].c);
			}
		}else if (z.size() > (n / 2)) {
			sort(z.begin(), z.end(), cmpz);
			int flag = z.size() - (n / 2);
			for (int i = 0; i < flag; i++) {
				ans -= l[z[i]].c - max(l[z[i]].a, l[z[i]].b);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

/*
This Problem is intersting!

I see, I like, I go agian...
*/
