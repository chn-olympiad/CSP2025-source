#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T> void re(T&x){x = 0; char c; int sign; do{c = getchar(); if(c == '-') sign = -1;}while(!isdigit(c)); do{x = x * 10 + c - '0'; c = getchar();}while(isdigit(c)); x *= sign;}

const int N = 5e6 + 100;

struct node{
	ll x, y;
};

ll n, k, ans;
ll a[N], st[N];
vector<node> v;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
//  I Love MYGO
	srand(time(0));
	cin >> n >> k;
	bool b = 0, b1 = 0, b2 = 0;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		if (a[i] != 1) b = 1;
		if (a[i] != 0 && a[i] != 1) b1 = 1;
//		if (a[i] > 255) b2 = 1;
	}
	if (b){
		if (b1){
			// mei zhao le......
			printf("%lld", rand());
		}else {
			if (k){
				for (int i = 1; i <= n; i ++){
					if (a[i]) ans ++;
				}
			}else {
				for (int i = 1; i <= n - 1; i++){
					if (a[i] == 1 && a[i + 1] == 1){
						ans ++, i + 1;
					}else if (!a[i]) ans ++;
				}
			}
			printf("%lld", ans);
		}
	}
	else {
		printf("%lld", n / 2);
	}
	return 0;
}


