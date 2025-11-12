#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxn = 505;

int n, m, tot;
int s[maxn], c[maxn];

void read(int &x){
	x = 0;
	int f = 1;
	char c = getchar();
	while (!isdigit(c)){
		if (c == '-'){
			f = -1;
		}
		c = getchar();
	}	
	while (isdigit(c)){
		x = x * 10 + c - 48;
		c = getchar();
	}
	x *= f;
	return ;
}

void write(int x){
	if (x < 0){
		x = -x;
		putchar('-');
	}	
	if (x >= 10){
		write(x / 10);
	}
	putchar(x % 10 + '0');
	return ;
}

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	read(n), read(m);
	bool flag_a = 1;
	string st;
	cin >> st;
	int len = st.size();
	for (int i = 0; i < len; ++i){
		if (st[i] == '1'){
			s[++tot] = 1;
		}
		else if (st[i] == '0'){
			s[++tot] = 0;
			flag_a = 0;
		}
	}
	for (int i = 1; i <= n; ++i){
		read(c[i]);
	}
	if (flag_a){
		long long ans = 1;
		sort(c + 1, c + n + 1, cmp);
		for (int i = n; i >= m; --i){
			int id = upper_bound(c + 1, c + n + 1, i) - c;
			ans *= id;
			ans %= mod;
		}
		cout << ans << "\n";
		return 0;
	}
	return 0;
}
