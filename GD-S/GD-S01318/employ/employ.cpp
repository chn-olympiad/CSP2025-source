#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll read(){
	ll res = 0, flg = 1; char c = getchar();
	for(; c > '9' || c < '0'; c = getchar()) if(c == '-') flg = -flg;
	for(; c >= '0' && c <= '9'; c = getchar()) res = (res << 3) + (res << 1) + c - '0';
	return res * flg;
}
void write(ll x, char c = '\n'){
	if(x < 0) putchar('-'), x = -x;
	static int stk[35]; int top = 0;
	do { stk[top++] = x % 10; x /= 10; } while(x);
	while(top) { putchar(stk[--top] + '0'); }
	putchar(c);
}
signed main(){

	return 0;
}

