#include <bits/stdc++.h>

using namespace std;


const int N = 1e5;
struct node {
	int a, b, c;
}a[N];


int n, ans;

void dfs(int u, int ca, int cb, int cc, int sum) {
	if(u >= n) {
		int ma = 0;
		if(ca < n / 2) ma = max(a[u].a, ma);
		if(cb < n / 2) ma = max(a[u].b, ma);
		if(cc < n / 2) ma = max(a[u].c, ma);
		ans = max(ans, sum + ma);
		return;
	}
//	cout << u;
	if(ca < n / 2) {
	dfs(u + 1, ca + 1, cb, cc, sum + a[u].a);}
	if(cb < n / 2) {
	dfs(u + 1, ca, cb + 1, cc, sum + a[u].b);}
	if(cc < n / 2) {
	dfs(u + 1, ca, cb, cc + 1, sum + a[u].c);}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	
	int t;
	cin >> t ;
	while(t--) {
		ans = 0;
		cin >> n ;
		for(int i = 1;i <= n;i++) {
			cin >> a[i].a >> a[i].b >> a[i].c ;
		}
//		cout << "1a"<< a[1].a <<' ';
		dfs(2, 1, 0, 0, a[1].a);
//		cout << "1b"<< a[1].b <<' ';
		dfs(2, 0, 1, 0, a[1].b);
//		cout << "1c"<< a[1].c <<' ';
		dfs(2, 0, 0, 1, a[1].c);
		
		cout << ans << endl ;
	}
} 
