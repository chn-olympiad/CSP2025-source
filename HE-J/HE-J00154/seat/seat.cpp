#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000005];

inline void pfmtpos(const int& pos) {
	int c = 1, r = 1;
	bool s = false;
	for (int i = 0; i < pos; i++) {
		if (s) c--;
		else c++;
		
		if (c > m) {
			r++;
			c--;
			s = true;
		} else if (c < 1) {
			r++;
			c++;
			s = false;
		}
	}
	cout << r << " " << c;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	const int rn = a[0];
	sort(a + 0, a + n * m);
	reverse(a + 0, a + n * m);
	for (int i = 0; i < n * m; i++) {
		if (a[i] == rn) {
			pfmtpos(i);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
