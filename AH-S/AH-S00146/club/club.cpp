#include <cstdio>
#include <algorithm>

using namespace std;

int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') { c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	return x;
}

#define MAXN 100000

int fMax(int a, int b) {
	if (a >= b) return a;
	return b;
}

int maxClub;

struct node {
	friend bool operator < (const node &a, const node &b) {
		if (a.choice == maxClub && b.choice != maxClub) return true;
		if (a.choice != maxClub && b.choice == maxClub) return false;
		return a.zv >= b.zv;
	}
	
	int a, b, c;
	int choice;
	int v, zv;
	
	void choose() {
		zv = 0;
		if (a >= b && a >= c) {
			choice = 1, v = a;
			zv = fMax(b - a, c - a);
		}
		else if (b >= a && b >= c) {
			choice = 2, v = b;
			zv = fMax(a - b, c - b);
		}
		else {
			choice = 3, v = c;
			zv = fMax(a - c, b - c);
		}
		return;
	}
};

int t;
int n;
node p[MAXN + 10];
int cnt[5];
int ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while (t--) {
		n = read();
		cnt[1] = cnt[2] = cnt[3] = 0;
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			p[i].a = read(), p[i].b = read(), p[i].c = read();
			p[i].choose();
			++cnt[p[i].choice];
			ans += p[i].v;
		}
		if (cnt[1] >= cnt[2] && cnt[1] >= cnt[3]) maxClub = 1;
		else if (cnt[2] >= cnt[1] && cnt[2] >= cnt[3]) maxClub = 2;
		else maxClub = 3;
		if (cnt[maxClub] > n / 2) {
			sort(p + 1, p + 1 + n);
			for (int i = 1; i <= cnt[maxClub] - n / 2; ++i) {
				ans += p[i].zv;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
