#include <bits/stdc++.h>
using namespace std;
//8分 
inline int read(){
	int cnt = 0, f = 1;
	char h = getchar();
	while(h < '0' || h > '9'){
		if(h == '-')f = -f;
		h = getchar();
	}
	while(h >= '0' && h <= '9'){
		cnt = (cnt << 3) + (cnt << 1) + (h ^ 48);
		h = getchar();
	}
	return cnt * f;
}

inline void write(int x){
	if(x < 0){
		putchar('-');
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x % 10 + '0');
}

const int N = 500 + 100, MOD = 998244353;
int n, m, ans;
int s[N];
struct node{
	int c;
	int id;
};
node a[N];
int w[N];

void check(){
	int cnt = 0;
	int js = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == 0){
			cnt++;
		}
		else{
			if(a[w[i]].c > cnt){
				js++;
			}
			else{
				cnt++;
			}
		}
	}
	if(js >= m){
		ans++;
		if(ans > MOD)ans -= MOD;
	}
	return;
}

void dfs(int x){//w[i] = x   x这个位置是i这个人 
	if(x == n + 1){
		check();
		return;
	}
	for(int i = 1; i <= n; i++){
		if(w[i] == 0){
			w[i] = x;
			dfs(x + 1);
			w[i] = 0;
		}
	}
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++){
		char h = getchar();
		s[i] = h - '0';
	}
	for(int i = 1; i <= n; i++){
		a[i].c = read();
		a[i].id = i;
	}
	dfs(1);
	write(ans);
	return 0;
}

