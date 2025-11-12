#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
/*
2 2 
99 100 97 98
*/
void solve(){
	int n,m,x,tot;
	cin >> n >> m >> x;
	vector<int> a(n * m + 1);
	a[1] = x;
	for(int i = 2;i <= n * m; i++) cin >> a[i];
	sort(a.begin() + 1,a.begin() + 1 + n * m,greater<int> ());
//	for(int i = 1;i <= n * m; i++) cout << a[i] << ' ';cout << endl;
	for(int i = 1;i <= m; i++){
		if(i % 2 == 1)
			for(int j = 1;j <= n; j++)
				if(a[++tot] == x){
					cout << i << ' ' << j << endl;
					return ;
				}
		if(i % 2 == 0)
			for(int j = n;j >= 1; j--)
				if(a[++tot] == x){
					cout << i << ' ' << j << endl;
					return ;
				}
	}
}
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	int T = 1;
	while(T--)
		solve();
	return 0;
} 
