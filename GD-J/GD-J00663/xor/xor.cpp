#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>
inline void read(T &x) {
	x = 0;
	bool flag = 0;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') flag = !flag;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}

	if(flag)x = -x;
}

template<typename T>
inline void write(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	ll n, k;
	read(n);
	read(k);
	
	vector<ll> a(n + 1);
	for(ll i = 1; i <= n; ++i) {
		read(a[i]);
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == k)ans++;
	}
	write(ans);
	return 0;
}


