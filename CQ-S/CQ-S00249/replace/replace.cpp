#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200100, M = 1001000, K = 15;
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

int n, q;
string s[N][2], t1, t2;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read();
	for (int i = 1; i <= n; i++){
		cin >> s[i][0] >> s[i][1];
	}
	while(q--){
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			puts("0");
			continue;
		}
		int t = t1.size();
		int l = -1, r = t;
		for (int i = 0; i < t; i++){
			if(t1[i] != t2[i]){
				l = i;
				break;
			}
		}
		for (int i = t - 1; i >= 0; i--){
			if(t1[i] != t2[i]){
				r = i;
				break;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			int lenth = s[i][0].size();
			if(lenth >= r - l + 1){
				for (int j = r - lenth + 1; j <= l; j++){
					string s_t1 = t1;
					bool f = 1;
					for (int k = 0; k < lenth; k++){
						if(s[i][0][k] != t1[j + k]){
							f = 0;
							break;
						}
					}
					if(f){
						for (int k = 0; k < lenth; k++){
							s_t1[j + k] = s[i][1][k];
						}
						if(s_t1 == t2)
							ans++;
					}
				}
			}
		}
		write(ans);
		puts("");
	}
	return 0;
}
