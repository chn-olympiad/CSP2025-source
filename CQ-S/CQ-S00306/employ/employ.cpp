#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x = 0 , f = 1;
	char ch = getchar();
	while(!('0' <= ch && ch <= '9')) {
		if(ch == '-')
			f = -f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
string read1() {
	string x;
	char ch = getchar();
	while(!('0' <= ch && ch <= '9')) ch = getchar();
	while('0' <= ch && ch <= '9') {
		x += ch;
		ch = getchar();
	}
	return x;
}

const int N = 1e2 + 5;
int c[N];
int choose[N];
int cnt = 0;
string s;
unordered_map<int , bool> ma;
int n = 0 , m = 0;
int ans = 0;

void dfs(int u , int have , int now) {
	if(u >= n+1) {
		if(now >= m)
			ans++;
		return;
	}
	for(int i = 1 ; i <= n ; i++) {
		if(ma[i]) continue;
		int temp = i;//choose
		ma[temp] = 1;
		choose[u] = temp;
		if(have >= c[temp] || s[u-1] == '0')
			dfs(u+1 , have+1 , now);
		else
			dfs(u+1 , have , now+1);
		choose[u] = 0;
		ma[temp] = 0;
	}
}

signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m ; 
	s = read1();
//	cin >> s;
	for(int i = 1 ; i <= n ; i++)
		cin >> c[i];
	dfs(1 , 0 , 0);
	cout << ans << "\n" ;

	return 0;
}
/*
3 2
101
1 1 2
*/

