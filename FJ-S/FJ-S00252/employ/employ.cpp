#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int cnt = 0, sign = 1;
	char c = getchar();
	while(!isdigit(c)){
		if(c == '-')	sign = -1;
		c = getchar();
	}
	while(isdigit(c)){
		cnt = (cnt << 1) + (cnt << 3) + (c ^ 48);
		c = getchar();
	}
	return cnt * sign;
}
int a[510];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n = read(), m = read();
	int mod = 998244353;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++){
		a[i] = read();
	}	
	ll ans = 1;
	for(int i = 1; i <= n; i++){
		ans = ans  * 1ll * i % mod;
	}
	printf("%lld", ans);
	return 0;
}

