#include <iostream>
#include <algorithm>
#define MAXN (20)

using namespace std;
int n, m;
int a[MAXN];

int b[MAXN];
int mp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i], b[i] = a[i];
	
	sort(b + 1, b + 1 + n * m, [](int x, int y) {
		return x > y;
	});
	
	for (int i = 1, t = 1; i <= n * m; i+=n, t++) {
		int c = i;
		if (!(t & 1)) {
			for (int j = n; j >= 1; j--)
				mp[j][t] = b[c ++];
		} else {
			for (int j = 1; j <= n; j++)
				mp[j][t] = b[c ++];
		}
	}
//	cout << a[1] << "\n";
	bool f = false;
	for (int i = 1; i <= n; i++) {
		if (f) break;
		for (int j = 1; j <= m; j++) {
//			cout << mp[i][j] << "[" << j<< ", " << i << "] ";
			if (mp[i][j] == a[1]) {
				f = true;
//				cout << mp[i][j] << "\n";
				cout << j << " " << i << "\n";
				break;
			}
		}
//		cout << "\n";
	}

    cout << flush;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
