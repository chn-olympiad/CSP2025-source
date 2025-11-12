#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read () {
	ll X = 0;bool O = false;char C = getchar();
	while (!(C >= '0' && C <= '9')) O ^= (C=='-'), C = getchar();
	while (C >= '0' && C <= '9') X = (X << 3) + (X << 1) + (C - '0'), C = getchar();
	if (O) X = -X;
	return X;
}
const int MAXN = 1e2 + 10;
int A[MAXN];
int T[MAXN];
int main () {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int N, M, Rindex = 1;
	cin >> N >> M;
	for (int i = 0; i < N * M; i++) {
		cin >> A[i];
		T[A[i]]++;
	}
	for (int i = 100; i >= 0; i--) {
		if (i == A[0]) {
			break;
		} else {
			Rindex += T[i];
		}
	}
	int C = int(ceil(1.0 * Rindex / N));
	int Mo = (Rindex % N) ? (Rindex % N) : (N);
	int R = C & 1 ? Mo : N + 1 - Mo;
	cout << C << " " << R;
	return 0;
} 
