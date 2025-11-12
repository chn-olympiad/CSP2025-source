# include <bits/stdc++.h>
# define N (100002)
using namespace std;

bool vis[5] = {0};
int T, n, num, ans, x[N];
struct node{
	int wb1, wb2, wb3;
	int maxn, minn;
}a[N];

int main( ) {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	
	while ( T-- ) {
		
		ans = 0;
		vis[1] = false; vis[2] = false; vis[3] = false;
		cin >> n;
		num = n/2;
		
		for ( int i = 1; i <= n; ++i ) {
			cin >> a[i].wb1 >> a[i].wb2 >> a[i].wb3;
			a[i].maxn = max( a[i].wb1, max( a[i].wb2, a[i].wb3 ) );
			a[i].minn = min( a[i].wb1, min( a[i].wb2, a[i].wb3 ) );
			x[i] = a[i].maxn;
		}
		
		if ( n == 2 ) {
			int lhx1 = a[1].wb1 + a[2].wb2;
			ans = max ( ans, lhx1 );
			int lhx2 = a[1].wb1 + a[2].wb3;
			ans = max ( ans, lhx2 );
			int lhx3 = a[1].wb2 + a[2].wb1;
			ans = max ( ans, lhx3 );
			int lhx4 = a[1].wb2 + a[2].wb3;
			ans = max ( ans, lhx4 );
			int lhx5 = a[1].wb3 + a[2].wb1;
			ans = max ( ans, lhx5 );
			int lhx6 = a[1].wb3 + a[2].wb2;
			ans = max ( ans, lhx6 );
			cout << ans << "\n";
			continue;
		}
		
		if ( n == 4 ) {
			int lhx01 = a[1].wb1 + a[2].wb1 + a[3].wb2 + a[4].wb2;
			ans = max ( ans, lhx01 );
			int lhx02 = a[1].wb1 + a[2].wb1 + a[3].wb2 + a[4].wb3;
			ans = max ( ans, lhx02 );
			int lhx03 = a[1].wb1 + a[2].wb1 + a[3].wb3 + a[4].wb2;
			ans = max ( ans, lhx03 );
			int lhx04 = a[1].wb1 + a[2].wb1 + a[3].wb3 + a[4].wb3;
			ans = max ( ans, lhx04 );
			int lhx05 = a[1].wb1 + a[2].wb2 + a[3].wb1 + a[4].wb2;
			ans = max ( ans, lhx05 );
			int lhx06 = a[1].wb1 + a[2].wb2 + a[3].wb1 + a[4].wb3;
			ans = max ( ans, lhx06 );
			int lhx07 = a[1].wb1 + a[2].wb2 + a[3].wb2 + a[4].wb1;
			ans = max ( ans, lhx07 );
			int lhx08 = a[1].wb1 + a[2].wb2 + a[3].wb2 + a[4].wb3;
			ans = max ( ans, lhx08 );
			int lhx09 = a[1].wb1 + a[2].wb2 + a[3].wb3 + a[4].wb1;
			ans = max ( ans, lhx09 );
			int lhx10 = a[1].wb1 + a[2].wb2 + a[3].wb3 + a[4].wb2;
			ans = max ( ans, lhx10 );
			int lhx11 = a[1].wb1 + a[2].wb2 + a[3].wb3 + a[4].wb3;
			ans = max ( ans, lhx11 );
			int lhx12 = a[1].wb1 + a[2].wb3 + a[3].wb1 + a[4].wb2;
			ans = max ( ans, lhx12 );
			int lhx13 = a[1].wb1 + a[2].wb3 + a[3].wb1 + a[4].wb3;
			ans = max ( ans, lhx13 );
			int lhx14 = a[1].wb1 + a[2].wb3 + a[3].wb2 + a[4].wb1;
			ans = max ( ans, lhx14 );
			int lhx15 = a[1].wb1 + a[2].wb3 + a[3].wb2 + a[4].wb2;
			ans = max ( ans, lhx15 );
			int lhx16 = a[1].wb1 + a[2].wb3 + a[3].wb2 + a[4].wb3;
			ans = max ( ans, lhx16 );
			int lhx17 = a[1].wb2 + a[2].wb1 + a[3].wb1 + a[4].wb2;
			ans = max ( ans, lhx17 );
			int lhx18 = a[1].wb2 + a[2].wb1 + a[3].wb1 + a[4].wb3;
			ans = max ( ans, lhx18 );
			int lhx19 = a[1].wb2 + a[2].wb1 + a[3].wb2 + a[4].wb1;
			ans = max ( ans, lhx19 );
			int lhx20 = a[1].wb2 + a[2].wb1 + a[3].wb2 + a[4].wb3;
			ans = max ( ans, lhx20 );
			int lhx21 = a[1].wb2 + a[2].wb1 + a[3].wb3 + a[4].wb1;
			ans = max ( ans, lhx21 );
			int lhx22 = a[1].wb2 + a[2].wb1 + a[3].wb3 + a[4].wb2;
			ans = max ( ans, lhx22 );
			int lhx23 = a[1].wb2 + a[2].wb1 + a[3].wb3 + a[4].wb3;
			ans = max ( ans, lhx23 );
			int lhx24 = a[1].wb2 + a[2].wb2 + a[3].wb1 + a[4].wb1;
			ans = max ( ans, lhx24 );
			int lhx25 = a[1].wb2 + a[2].wb2 + a[3].wb1 + a[4].wb3;
			ans = max ( ans, lhx25 );
			int lhx26 = a[1].wb2 + a[2].wb2 + a[3].wb3 + a[4].wb1;
			ans = max ( ans, lhx26 );
			int lhx27 = a[1].wb2 + a[2].wb2 + a[3].wb3 + a[4].wb3;
			ans = max ( ans, lhx27 );
			int lhx28 = a[1].wb2 + a[2].wb3 + a[3].wb1 + a[4].wb1;
			ans = max ( ans, lhx28 );
			int lhx29 = a[1].wb2 + a[2].wb3 + a[3].wb1 + a[4].wb2;
			ans = max ( ans, lhx29 );
			int lhx30 = a[1].wb2 + a[2].wb3 + a[3].wb1 + a[4].wb3;
			ans = max ( ans, lhx30 );
			int lhx31 = a[1].wb2 + a[2].wb3 + a[3].wb2 + a[4].wb1;
			ans = max ( ans, lhx31 );
			int lhx32 = a[1].wb2 + a[2].wb3 + a[3].wb2 + a[4].wb3;
			ans = max ( ans, lhx32 );
			int lhx33 = a[1].wb2 + a[2].wb3 + a[3].wb3 + a[4].wb1;
			ans = max ( ans, lhx33 );
			int lhx34 = a[1].wb2 + a[2].wb3 + a[3].wb3 + a[4].wb2;
			ans = max ( ans, lhx34 );
			int lhx35 = a[1].wb3 + a[2].wb1 + a[3].wb1 + a[4].wb2;
			ans = max ( ans, lhx35 );
			int lhx36 = a[1].wb3 + a[2].wb1 + a[3].wb1 + a[4].wb3;
			ans = max ( ans, lhx36 );
			int lhx37 = a[1].wb3 + a[2].wb1 + a[3].wb2 + a[4].wb1;
			ans = max ( ans, lhx37 );
			int lhx38 = a[1].wb3 + a[2].wb1 + a[3].wb2 + a[4].wb2;
			ans = max ( ans, lhx38 );
			int lhx39 = a[1].wb3 + a[2].wb1 + a[3].wb2 + a[4].wb3;
			ans = max ( ans, lhx39 );
			int lhx40 = a[1].wb3 + a[2].wb1 + a[3].wb3 + a[4].wb1;
			ans = max ( ans, lhx40 );
			int lhx41 = a[1].wb3 + a[2].wb1 + a[3].wb3 + a[4].wb2;
			ans = max ( ans, lhx41 );
			int lhx42 = a[1].wb3 + a[2].wb2 + a[3].wb1 + a[4].wb1;
			ans = max ( ans, lhx42 );
			int lhx43 = a[1].wb3 + a[2].wb2 + a[3].wb1 + a[4].wb2;
			ans = max ( ans, lhx43 );
			int lhx44 = a[1].wb3 + a[2].wb2 + a[3].wb1 + a[4].wb3;
			ans = max ( ans, lhx44 );
			int lhx45 = a[1].wb3 + a[2].wb2 + a[3].wb2 + a[4].wb1;
			ans = max ( ans, lhx45 );
			int lhx46 = a[1].wb3 + a[2].wb2 + a[3].wb2 + a[4].wb3;
			ans = max ( ans, lhx46 );
			int lhx47 = a[1].wb3 + a[2].wb2 + a[3].wb3 + a[4].wb1;
			ans = max ( ans, lhx47 );
			int lhx48 = a[1].wb3 + a[2].wb2 + a[3].wb3 + a[4].wb2;
			ans = max ( ans, lhx48 );
			int lhx49 = a[1].wb3 + a[2].wb3 + a[3].wb1 + a[4].wb1;
			ans = max ( ans, lhx49 );
			int lhx50 = a[1].wb3 + a[2].wb3 + a[3].wb1 + a[4].wb2;
			ans = max ( ans, lhx50 );
			int lhx51 = a[1].wb3 + a[2].wb3 + a[3].wb2 + a[4].wb1;
			ans = max ( ans, lhx51 );
			int lhx52 = a[1].wb3 + a[2].wb3 + a[3].wb2 + a[4].wb2;
			ans = max ( ans, lhx52 );
			cout << ans << "\n";
			continue;
		}
		
		sort( x + 1, x + n + 1 );
		
		for ( int i = 1; i <= num; ++i ) {
			ans += x[n - i + 1];
		}	
		
		cout << ans << "\n";
	
	}
	
	return 0;
}
