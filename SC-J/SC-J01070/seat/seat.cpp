#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n * m +1 );
	for(int i = 1; i <= n * m; i ++ ) {
		cin >> a[i];
	}
	
	int num = a[1];
	sort(a.begin() + 1, a.end(),[](int b1, int b2){
		return b1 > b2;
	});
	
	int idx;
	for(int i = 1; i <= n * m; i ++ ){
		if(a[i] == num) {
			idx = i;
			break;
		}
			
	}
	int row = (idx % n == 0 ? n : idx % n);
	int col = (idx - row) / n + 1;
//	int col = idx / n + 1;
//	int row = idx-(col - 1) * n;
//	cout << idx << endl;
//	cout << col << ' ' << row << endl;
	if(col % 2 == 0) {
		row = n + 1 - row;
	}
	cout << col << ' ' << row << endl;
	
}
signed main() {
	
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int t= 1;
	while(t--) solve();
	
	
	return 0;
}