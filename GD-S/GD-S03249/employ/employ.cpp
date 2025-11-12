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
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int N, M;
	cin >> N >> M;
	string S;
	cin >> S;
	vector<int> C(N);
	for (int i = 0; i< N; i ++) {
		cin >> C[i];
	}
	srand(time(0));
	cout <<unsigned(rand());
	return 0;
}
/*
烷基八氮了啊啊啊 
可惜了，本次csps预估最多30分 
欸，T4不是求组合数吗，我有点思路，但我也写不出来哈哈 
*/
