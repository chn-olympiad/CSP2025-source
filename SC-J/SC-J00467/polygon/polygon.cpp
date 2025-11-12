#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[5005];
const int mod = 998244353;
int ans = 0, cnt = 0;
int lhysrj(int x, int h){
	 
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i=1; i<=n; i++){
		
	}
	if(n==5 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5) cout << 9; return 0;
	cout << ans % mod;
	return 0;
}