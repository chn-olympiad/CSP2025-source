#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5e2+5, mod = 998244353;
int n, m, cnt = 0;
int c[MAXN], s[MAXN];

bool flag = true;

int jc(int n){
	int ans = 1;
	for(int i = 2; i <= n; i++){
		ans *= n;
		ans %= mod;
	}
	return ans;
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= n; i++){
		char ch = getchar();
		s[i] = ch-'0';
		if(s[i] == 1) cnt++;
		if(s[i] > 1) flag = false;
	}
	for(int i = 1; i <= n; i++) scanf("%lld", &c[i]);
	
	if(flag){
		if(n == 1){
			if(m <= 1){
				cout << 1;
				return 0;
			}else{
				cout << 0;
				return 0;
			}
		}
		if(m <= cnt){
			cout << jc(n);
		}else{
			cout << 0;
		}
	}
	
	
	return 0;
}