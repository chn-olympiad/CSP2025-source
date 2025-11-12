/*
100+[64,100]+0+8=[172,208]
别样的挂分大赛 
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int mod = 998244353;
long long n,m;
string s;
long long a[N];
bool vis[N];
long long ans;
long long b[N];
void dfs(int x,int no) {
//	cout << x << ' ' << no << endl;
	if(no > n - m) return ;
	if(x == n + 1) {
		if(no <= n - m) {
			ans = (ans + 1) % mod;
			return ;	
		}
	}
	for(int i = 1;i <= n;i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		b[x] = a[i];
		if(no >= a[i] || s[x] == '0') dfs(x + 1,no + 1);
		else dfs(x + 1,no);
		vis[i] = 0; 
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	dfs(1,0);
	cout << ans;
	return 0;
}
/*
10 1
111111111111
1 1 1 1 1 1 1 1 1 1 1 1
*/
