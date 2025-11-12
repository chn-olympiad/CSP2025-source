#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) { return a>b; }
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<int> a(n*m);
	for (auto &i : a) cin >> i;

	int ming = a[0], idx = 0, pos = 0;

    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n*m; i++, idx++) {
        if (a[i] == ming) break;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++, pos++) {
            if (pos == idx) {
                if (i % 2 == 0) {
                    cout << i+1 << " " << j+1;
                    return 0;
                } else {
                    cout << i+1 << " " << m-j;
                    return 0;
                }
            }
        }
    }

	return 0;
}
