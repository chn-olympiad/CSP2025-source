//60pts + 5pts 特殊性质C未写
#include<bits/stdc++.h>
//bool Mst;
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N], s[N];
int dp[N];

//bool Med;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cerr << abs((&Mst)-(&Med)) / 1024.0 / 1024 << "MB" << '\n';
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] ^ a[i];
	
	if(n <= 1e3){
		for(int i = 1; i <= n; ++i){
			dp[i] = dp[i - 1];
	//		cerr << i << " is from:\n";
			for(int j = 0; j < i; ++j){
				if((s[i] ^ s[j]) == m){
	//				cerr << j << ' ';
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
	//		cerr << '\n' << "And then get " << dp[i] << "\n\n";
		}
		cout << dp[n];
		return 0;
	}
	
	//特殊性质B
	if(m == 1){
		int ans = 0;
		for(int i = 1; i <= n; ++i) ans += a[i];
		cout << ans;
	}
	else {
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			if(a[i] == 0) ++ans;
			else if(i > 1 && a[i - 1] == 1) ++ans;
		}
		cout << ans;
	}
	
	return 0;
} 
