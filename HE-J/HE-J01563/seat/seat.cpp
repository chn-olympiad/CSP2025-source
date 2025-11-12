#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T> void re(T&x){x = 0; char c; int sign; do{c = getchar(); if(c == '-') sign = -1;}while(!isdigit(c)); do{x = x * 10 + c - '0'; c = getchar();}while(isdigit(c)); x *= sign;}

ll h, l, n;
ll a1;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
//	I Love MYGO
	cin >> h >> l >> a1;
	n = h * l;
	ll cnt = 0;
//	cout << n;
	for (int i = 2, x; i <= n; i ++){
		cin >> x;
		if (x > a1) cnt ++;
	}
	cnt += 1;
	if (cnt % h == 0){
		if ((cnt / h) % 2 == 0){
			printf("%lld %lld", cnt / h, 1);
		}else {
			printf("%lld %lld", cnt / h, h);
		}
	}else {
		if ((cnt / h + 1) % 2 == 0){
			printf("%lld %lld", cnt / h + 1, h + 1 - cnt % h);
		}else {
			printf("%lld %lld", cnt / h + 1, cnt % h);
		}
	}
	return 0;
}


