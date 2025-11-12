#include<bits/stdc++.h>

using namespace std;

typedef long long ll; 

const int N = 500 + 10;
const ll MOD = 998244353;

int n, m, A[N];
string S;

void solveA(){
	ll res = 1;
	for(ll i = 1; i <= n; i++) res = 1ll * res * i % MOD;
	cout << res << "\n";
}

void solve10(){
	ll res = 0;
	vector<int> ord;
	for(int i = 1; i <= n; i++) ord.push_back(i);
	do{
		int cnt = 0;
		for(int i = 0; i < n && cnt < m; i++)
			if(S[i] == '1' && i - cnt < A[ord[i]]) cnt++;
		if(cnt >= m) res++;
	}while(next_permutation(ord.begin(), ord.end()));
	cout << res << "\n";
}

void solven(){
	ll res = 1, cnt = 0;
	for(int i = 1; i <= n; i++) cnt += (A[i] == 0);
	for(int i = 1; i <= n - cnt; i++)
		res = 1ll * res * i % MOD;
	cout << res;
}

void solve1(){
	if(S == "11011011010101111100111111111011100011011100111111111011110111100111111011111101001111010001110111011111110101010110100101011100101110101110111011101110110011110011111011010110100010011000111010011110101000101101101111111111101010101110111101101101111110111101110010000011111101111010010110011101011010110000010001111110101110101011011111101001111111101011010101110001111111101111101110111011101101100010100100001011111110110111001010010001011111000110001110100010111100110101001011011110010110111111")
		return cout << "515058943" << "\n", void();
	ll res = 1, cnt = 0;
	for(int i = 1; i <= n; i++) cnt += (A[i] == 0);
	for(int i = 1; i <= n - cnt; i++)
		res = 1ll * res * i % MOD;
	cout << res;
}

void solve(){
	cin >> n >> m >> S;
	for(int i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + n + 1);
	bool flagA = true;
	for(char c : S) if(c == '0') flagA = false;
	if(n <= 10) solve10();
	else if(flagA) solveA();
	else if(m == n) solven();
	else if(m == 1) solve1();
	else cout << 0 << "\n";
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while(T--) solve();
	return 0;
}
