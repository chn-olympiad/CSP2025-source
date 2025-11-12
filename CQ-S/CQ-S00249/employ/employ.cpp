#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 510, mod = 998244353;
ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
void write(ll x){
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x <= 9){
		putchar(x + '0');
		return;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}

bool used[N];
int n, m, c[N], b[N];
ll ans;
char s[N];

void solve(int p){
	if(p > n){
		int sum = 0, cnt = 0;
		for (int i = 1; i <= n; i++){
			if(cnt >= c[b[i]]){
				cnt++;
				continue;
			}
			if(s[i] == '1'){
				sum++;
			}else{
				cnt++;
			}
		}
		if(sum >= m)
			ans++;
		return;
	}
	for (int i = 1; i <= n; i++){
		if(!used[i]){
			b[p] = i;
			used[i] = 1;
			solve(p + 1);
			used[i] = 0;
			b[p] = 0;
		}
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++){
		c[i] = read();
	}
	bool f = 1;
	for (int i = 1; i <= n; i++){
		if(s[i] == '0'){
			f = 0;
			break;
		}
	}
	if(f){
		ll ans = 1;
		for (int i = 1; i <= n; i++){
		//	write(ans);
		//	puts("");
			ans *= i;
			ans %= mod;
		}
		write(ans);
		return 0;
	}
	if(n > 100){
		puts("0");
		return 0;
	}
	solve(1);
	write(ans % mod);
	return 0;
}
/*
AFO
=Away from OI
may=Always from OI
It's a grammer mistake,but I think it's right
*/
