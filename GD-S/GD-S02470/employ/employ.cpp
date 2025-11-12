#include<bits/stdc++.h>
using namespace std;
const int N = 601;
long long modn = 998244353ll;
int modn2 = 998244353;
int n,m;
string s;
int a[N],d[N];
long long ans = 0ll;
int fl[N],answ[N];
void dfs(int x){
	if(x > n){
		int cnt = 0,ct = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == 0) cnt++;
			else{
				if(cnt >= d[answ[i]]) cnt++;
				else{
					ct++;
				}
			}
		}
		if(ct >= m) ans = (ans + 1ll) % modn; 
	}else{
		for(int i = 1;i <= n;i++){
			if(fl[i] == 1) continue;
			else{
				fl[i] = 1;
				answ[x] = i;
				dfs(x + 1);
				fl[i] = 0;
			}
		}
	}
}
long long f(int x){
	long long dp = 1ll;
	for(int i = 2;i <= x;i++){
		dp = (dp * i) % modn;
	}
	return dp;
}
int lowb(int x){
	return x & (-x);
}
int g(int x){
	int cnt2 = 0;
	while(x > 0){
		cnt2++;
		x ^= lowb(x);
	}
	return cnt2;
}
int h(int x){
	int cnt3 = 0;
	while(x > 0){
		cnt3++;
		x >>= 1;
	}
	return cnt3;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 0;i < n;i++) a[i+1] = s[i] - '0';
	for(int i = 1;i <= n;i++) cin >> d[i];
	for(int i = 1;i <= n;i++) fl[i] = 0;
	if(n <= 12){
		dfs(1);	
		cout << ans;
	}else{
		if(m == n){
			int op = 1;
			for(int i = 1;i <= n;i++){
				op &= a[i];
			}
			if(op == 0) cout << 0;
			else cout << f(n);
		}else if(m == 1){
			
		}else{
			cout << f(n);
		}
	}
	return 0;
}
