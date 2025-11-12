#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

#define fi first
#define se second

int n, m;
pii a[114];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1; i<=n*m; ++i){
		cin >> a[i].fi; a[i].se = i;
	}
	sort(a + 1, a + n*m + 1, greater<>());
	int Row = 0, Column = 1, tag = 1;
	for(int i=1; i<=n*m; ++i){
		Row += tag;
		if(Row > n){
			tag = -1;
			Row = n;
			++ Column;
		} else if(Row == 0){
			tag = 1;
			Row = 1;
			++ Column;
		}
		// cout << Row << ' ' << Column << '\n';
		if(a[i].se == 1){
			cout << Column << ' ' << Row << '\n';
		}
	}
	return 0;
}
