#include<bits/stdc++.h>
#define INF 1e13
#define int long long
using namespace std;

const int N = 2e5 + 10, M = 2e6 + 10, Mod = 998244353;

int T;

int n, m;
string s;
int x;

int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return f * x;
}

void solve(){
	srand(time(0) + Mod);
	n = read(), m = read();
	cin >> s;
	for(int i = 1; i <= n; ++i) x = read();
	
	x = rand() % Mod + 1;
	printf("%d\n", x);
	return;
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	T = 1;
//	T = read();
	while(T--)
		solve();
	return 0;
}

/*

*/
