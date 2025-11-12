#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
struct Node{
	int x, y, z;
}a[N];
int T, n;
bool cmp(Node u, Node v){
	return u.x == v.x ? u.y > v.y : u.x > v.x;
}
void calc1(){
	sort(a + 1, a + n + 1, cmp);
	int res = 0;
	for(int i = 1; i <= n / 2; ++i) res += a[i].x;
	cout << res << endl;
}
void calc2(){
	sort(a + 1, a + n + 1, cmp);
	int res = 0, cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(a[i].x >= a[i].y && cnt < n / 2) res += a[i].x, cnt++;
		else res += a[i].y; 
	}
	cout << res << endl;
}
int p1[N], p2[N], p3[N], ans;
void dfs(int u, int c1, int c2, int c3){
	if(c1 > n / 2 || c2 > n / 2 || c3 > n / 2) return ;
	if(u > n){
		int res = 0;
		for(int i = 1; i <= c1; ++i) res += a[p1[i]].x;
		for(int i = 1; i <= c2; ++i) res += a[p2[i]].y;
		for(int i = 1; i <= c3; ++i) res += a[p3[i]].z;
		ans = max(ans, res);
		return ; 
	}
	p1[c1 + 1] = u;
	dfs(u + 1, c1 + 1, c2, c3);
	p1[c1 + 1] = 0;
	p2[c2 + 1] = u;
	dfs(u + 1, c1, c2 + 1, c3);
	p2[c2 + 1] = 0;
	p3[c3 + 1] = u;
	dfs(u + 1, c1, c2, c3 + 1);
	p3[c3 + 1] = 0;
}
void calc3(){
	memset(p1, 0, sizeof p1);
	memset(p2, 0, sizeof p2);
	memset(p3, 0, sizeof p3);
	ans = 0;
	dfs(1, 0, 0, 0);
	cout << ans << endl;
}
void solve(){
	cin >> n;
	int flg1 = 1, flg2 = 1;
	for(int i = 1; i <= n; ++i){
		cin >> a[i].x >> a[i].y >> a[i].z;
		if(a[i].y != 0 && a[i].z != 0) flg1 = 0;
		if(a[i].z != 0) flg2 = 0;
	}
	if(n < 20) calc3();
	else if(flg1) calc1();
	else if(flg2) calc2();
	else calc3();
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) solve();
	return 0;
}

