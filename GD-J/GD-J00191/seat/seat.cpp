#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 101;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int>num (MAXN);
	int an;
	cin >> an;
	num[1] = an;
	for (int i = 2; i <= n * m; i++) {
		cin >> num[i];
	}
	sort(num.begin() + 1, num.begin() + n * m + 1, cmp);
	vector<vector<int>>a (MAXN, vector<int>(MAXN));
	int t = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[j][i] = num[t++];
			if (a[j][i] == an) {
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
