/*********************
 ~AUTHOR BY "ILWF^_^"
 ~author by "ILWF^_^"
*********************/
#include<bits/stdc++.h>
#define ILW return
#define F 0
using namespace std;
using ll = long long;
const ll N = 200005;
const ll mod = 1e9 + 7;
pair<ll,ll> a[N];
ll n , m , q;
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i].first , a[i].second = i;
	sort(a + 1 , a + n * m + 1);
	reverse(a + 1 , a + n * m + 1);
	ll loc = 1;
	for(int i = 1;i <= n * m;i++) if(a[i].second == 1) loc = i;
	ll r = loc / n + (loc % n != 0);
	cout << r << ' ';
	if(r % 2 == 1){
		if(loc % n == 0) cout << n;
		else cout << loc % n;
	}else{
		if(loc % n != 0) cout << n - loc % n + 1;
		else cout << 1;
	}
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
	//cin >> t;
	while(t--) solve();
	ILW F;
}
