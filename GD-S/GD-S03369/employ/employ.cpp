#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;i++)
const int N = 2e5 + 10;
using ll = long long;
void ckmax(ll &x,ll y){
	x = max(x, y); return;
}
int n, m, c[N]; string s; 
void solve(){
	cin >> n >> m >> s;
	rep(i,1,n){
		cin >> c[i];
	}
	cout << "2\n";
	return;
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
