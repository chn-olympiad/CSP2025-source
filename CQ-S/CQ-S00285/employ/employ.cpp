#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool stt;
const int N = 18;
const int mod = 998244353;
ll dp[1 << N][N + 1], ans;
int n, m, c[N], flagA = 1;
string s;
bool edd;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	dp[0][0] = 1;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != '1'){
			flagA = 0;
		}
	}
	for(int i = 0; i < n; i++) scanf("%d", &c[i]);
	if(n <= 18){
		for(int msk = 0; msk < (1 << n); msk++){
			int cnt = 0;
			for(int i = 0; i < n; i++){
				if((1 << i) & msk)
					cnt++;
			}
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if((1 << j) & msk) continue;
					if(s[cnt] == '0' || i >= c[j]){
						dp[msk | (1 << j)][i + 1] = (dp[msk | (1 << j)][i + 1] + dp[msk][i]) % mod;
					}else{
						dp[msk | (1 << j)][i] = (dp[msk | (1 << j)][i] + dp[msk][i]) % mod;
					}
						
				}
				if(msk == (1 << n) - 1){
					if(n - i >= m){
						ans = (ans + dp[msk][i]) % mod;
					}
				}
			}
		}		
		printf("%lld", ans);
	}else{
		ans = 1;
		for(int i = 1; i <= n; i++){
			ans = (ans * i) % mod; 
		}
		printf("%lld", ans);
	}
	
}

