#include <bits/stdc++.h>

constexpr int N = 1e5 + 10;

using namespace std;

struct node {
    int val, idx;
}a[N];

bool cmp(node x, node y) {
    return x.val > y.val;
}

int n, m;


void Debug() {

}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
        cin >> a[i].val;
        a[i].idx = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	int cnt = 0;
	int x = 1, y = 1;
	while (cnt <= n * m) {
        cnt += 1;
        if (a[cnt].idx == 1) {
            cout << x << ' ' << y << '\n';
            return 0;
        }
        if (x % 2) y += 1;
        else y -= 1;
        if (y > n || y < 1) {
            x += 1;
            if (y > n) y = n;
            else y = 1;
        }
	}
	return 0;
}
