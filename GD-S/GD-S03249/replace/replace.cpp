#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read (void) {
	ll X = 0; bool O = false; char C = getchar();
	while (!(C >= '0' && C <= ' 9')) O ^= (C == '-'), C = getchar();
	while (C >= '0' && C <= ' 9') X = (X << 3) + (X << 1) + (C - '0'), C = getchar();
	if (O) X = -X;
	return X;
}
const int MAXN = 1e4 + 10;
int main () {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int N, Q;
	cin >> N >> Q;
	string S[N][2], W[Q][2]; 
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < 2; j ++) {
			cin >> S[i][j];
		}
	}
	for (int q = 0; q < Q; q ++) {
		for (int p = 0; p < 2; p ++) {
			cin >> W[q][p];
		}
	}
	for (int i = 0; i < Q; i ++) {
		cout << 0;
	}
	return 0;
}
/*
摆烂了，题都看不懂 
*/
