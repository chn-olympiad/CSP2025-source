#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
const int N = 100005;
using namespace std;

int T;
int n;
int a[N][5];

struct ab {
	int a, id;
} p[5];

bool operator<(ab a, ab b) {
	return a.a > b.a;
}

int maxid[N], secid[N], dis[N];
int cnt[5], ex[N];

void ini() {
	cnt[0] = cnt[1] = cnt[2] = 0;
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		ini();
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			p[0].a = a[i][0], p[0].id = 0;
			p[1].a = a[i][1], p[1].id = 1;
			p[2].a = a[i][2], p[2].id = 2;
			sort(p, p + 3);
			maxid[i] = p[0].id, secid[i] = p[1].id;
			ans += p[0].a;
//			cout << p[0].a << endl;
			cnt[p[0].id]++;
			dis[i] = p[0].a - p[1].a;
		}
//		cout << ans << endl;
		
		int outid = -1;
		for (int i = 0; i <= 2; i++)
			if (cnt[i] > n / 2)
				outid = i;
		if (outid == -1) {
			cout << ans << endl;
			continue;
		}
		
		int id = 0;
		for (int i = 1; i <= n; i++)
			if (maxid[i] == outid)
				ex[++id] = dis[i];
		sort(ex + 1, ex + id + 1);
		for (int i = 1; i <= cnt[outid] - n / 2; i++)
			ans -= ex[i];
		cout << ans << endl;
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

