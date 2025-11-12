#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define F(i,j,k) for(int i=j;i<=k;i++)
#define D(i,j,k) for(int i=j;i>=k;i--)
#define int long long
const int N = 2e5+100;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int>A(n*m + 1);

	F(i, 1, n*m)cin >> A[i];
	int tg = A[1];
	sort(A.begin() + 1, A.end(), greater<int>());

	F(j, 1, m) {
		int f = (j - 1) * n;
		if (j % 2 == 1) {
			F(i, 1, n) {
				f++;
				if (A[f] == tg) {
					swap(i, j);
					return cout << i << " " << j << '\n', 0;
				}
			}
		} else {
			D(i, n, 1) {
				f++;
				if (A[f] == tg) {
					swap(i, j);
					return cout << i << " " << j << '\n', 0;
				}
			}
		}

	}
	return 0;
}