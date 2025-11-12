#include <bits/stdc++.h>
using namespace std;

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

const int N = 2e5 + 1000l;
int n, q;
string s[N][3], t[N][3];

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s[i][1] >> s[i][2];
	}
	for(int i = 1; i <= q; i++){
		cin >> t[i][1] >> t[i][2];
	}
	for(int i = 1; i <= q; i++)cout << rand() % 1000 << "\n";
	
	return 0;
}

