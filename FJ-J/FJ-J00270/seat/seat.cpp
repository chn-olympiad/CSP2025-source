#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
//#define int long long
//#define int unsigned long long
/*
T2 ended at 9:21
*/
using namespace std;
const int N = 1e4+10;
int la,posla,n,m,a[N];
bool cmp(int a,int b) {return a > b;}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> la;
	a[1] = la;
	for(int i = 2; i <= n*m; i++) cin >> a[i];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i = 1; i <= n*m; i++) if(la == a[i]) posla = i;
	int L = ceil(1.0*posla/n);
	cout << L << " ";
	if(L % 2 == 0){for(int i = n*(L-1)+1; i <= n*L; i++) if(a[i] == la) cout << n-(i-n*(L-1))+1; return 0;} 
	for(int i = n*(L-1)+1; i <= n*L; i++) if(a[i] == la) cout << i-n*(L-1);
	return 0;
}
