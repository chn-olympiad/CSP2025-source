#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;

/*
est. score : 8+4=12

est. total : [0,45]+[0,40]+[10-eps,10+eps],[12-eps,12+eps] = [22-eps,107+eps]
*/

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int N, M;cin >> N >> M;
	string S;cin >> S;
	int P[N];
	for (int i=0;i<N;i++) cin >> P[i];
	bool check=1, check2=1;
	for (int i=0;i<N;i++) check&=(S[i]-'0');
	for (int i=0;i<N;i++) check2&=(bool)P[i];
	if (N==M) {
		// Test case 15 : N==M
		if (!check||!check2) {
			cout << 0;
			return 0;
		}
		long long r=1;
		for (long long i=1;i<=N;i++) r*=i, r%=MOD;
		cout << r;
		return 0;
	}
	int order[N];
	for (int i=0;i<N;i++) order[i]=i;
	long long ans=0;
	do {
		int dq=0;
		for (int i=0;i<N;i++) {
			if (dq>=P[order[i]]||S[i]=='0') dq++;
		}
		if (N-dq>=M) {
			ans++;
			ans%=MOD;
		}
	}
	while (next_permutation(order, order+N));
	cout << ans;
	return 0;
}
