#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;

struct str {
    int a, b, c;
} a[MAX_N];

int t;
int n;
int maxx = -1;

void dfs (int k, int ans, int x, int y, int z) {
    if (x + y + z == n) {
        maxx = max (maxx, ans);
        return;
    }

    if (x + 1 <= n / 2) {
        dfs (k + 1, ans + a[k].a, x + 1, y, z);
    }

    if (y + 1 <= n / 2) {
        dfs (k + 1, ans + a[k].b, x, y + 1, z);
    }

    if (z + 1 <= n / 2) {
        dfs (k + 1, ans + a[k].c, x, y, z + 1);
    }
}

void dfs2 (int k, int ans, int x, int y) {
    if (x + y == n) {
        maxx = max (maxx, ans);
        return;
    }

    if (x + 1 <= n / 2) {
        dfs2 (k + 1, ans + a[k].a, x + 1, y);
    }

    if (y + 1 <= n / 2) {
        dfs2(k + 1, ans + a[k].b, x, y + 1);
    }
}

bool cmp (str a, str b) {
    return a.a > b.a;
}

int main () {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
	cin >> t;
	while (t--) {
        cin >> n;
        bool f = 1, fl = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].a >> a[i].b >> a[i].c;
            if (a[i].c > 0 || a[i].b > 0) {
                f = 0;
            }
            if (a[i].c > 0) {
                fl = 0;
            }
        }
        if (f) {
            sort (a + 1, a + n + 1, cmp);
            int l = 0;
            for (int i = 1; i <= n / 2; i++) {
                l = l + a[i].a;
            }
            cout << l << endl;
            continue;
        } else if (fl == 1) {
            maxx = -1;
            dfs2 (1, 0, 0, 0);
            cout << maxx << endl;
        } else {
            maxx = -1;
            dfs (1, 0, 0, 0, 0);
            cout << maxx << endl;
        }


	}

	//AC
	//rp++
	return 0;
}
