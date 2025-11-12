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
int C[20];
int main () {
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	// freopen("number4.in", "r", stdin);
	string S;
	cin >> S;
	int SL = S.length();
	for (int i = 0; i < SL; i++) {
		if (S[i] >= '0' && S[i] <= '9') C[S[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		while (C[i] > 0) {
			C[i]--;
			cout << i;
		}
	}
	return 0;
} 
