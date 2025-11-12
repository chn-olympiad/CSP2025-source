//yu gu 20 fen
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M;
int DP[1000005][25]; // yi can jia de ren de zhuang tai wei i, lu yong le j ren
string Arr;
int Arr2[25];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> N >> M >> Arr;
	//Arr = Arr;
	for(int i = 0; i < N; i++) {
		cin >> Arr2[i];
	}
	DP[0][0] = 1;
	int Ans = 0;
	for(int i = 0; i < (1 << N); i++) {
		int PCount = __builtin_popcount(i);
		for(int j = 0; j <= PCount; j++) {
			//cerr << i << ' ' << j << ' ' << PCount << '\n';
			if(i == (1 << N) - 1 && j >= M) {
				Ans += DP[i][j];
				Ans %= 998244353;
			}
			if(i == (1 << N) - 1) continue;
			//cerr << "A\n";
			for(int k = 0; k < N; k++) {
				if(i & (1 << k)) continue;
				int RevJ = PCount - j;
				//cerr << k << ' ' << (i | (1 << k)) << '\n';
				if(Arr[PCount] == '0' || RevJ >= Arr2[k]) {
					DP[i | (1 << k)][j] += DP[i][j];
				}else{
					DP[i | (1 << k)][j + 1] += DP[i][j];
				}
			}
		}
	}
	cout << Ans << '\n';
	return 0;
}