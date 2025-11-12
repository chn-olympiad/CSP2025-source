#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T> void re(T&x){x = 0; char c; int sign; do{c = getchar(); if(c == '-') sign = -1;}while(!isdigit(c)); do{x = x * 10 + c - '0'; c = getchar();}while(isdigit(c)); x *= sign;}

const int N = 2e6 + 100;

string s;
ll a[N];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//  I Love MYGO
	cin >> s;
	ll cnt = 0;
	for (int i = 0; i < s.size(); i ++){
		if (isdigit(s[i])) a[++ cnt] = s[i] - '0';
	}
	sort(a + 1, a + cnt + 1);
	for (int i = cnt; i >= 1; i --){
		printf("%lld", a[i]);
	}
	return 0;
}


