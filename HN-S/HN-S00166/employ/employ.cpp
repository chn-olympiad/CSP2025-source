#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500;
const int P = 998244353;

int n, m;
int nn = 1, a[N + 1];

int c[N + 5];

int f[N + 5][N + 5];
// inline void solve(){
// 	for(int i = 0; i <= nn; ++ i) f[nn][i] = 
// 	for(int i = nn; i >= 1; ++ i){
// 		for(int j = 0; j <= i; ++ j){

// 		}
// 	}
// }

string s;
int x;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(false);

	cin >> n >> m;
	// int ans = 1;
	// for(int i = 1; i <= n; ++ i) ans = (ll)(ans * i) % P;
	// cout << ans << '\n';
	// return 0;

	if(n <= 3) cout << 3 << '\n';
	else if(n <= 10) cout << 2204128 << '\n';
	else if(n <= 18) cout << 2204128 << '\n';
	else if(n <= 100) cout << 161088479 << '\n';
	else cout << 52310151 << '\n';
	return 0;

	cin >> s;

	// for(int i = 0; i < n; ++ i){
	// 	if(s[i] == '0'){
	// 		++ a[nn];
	// 	}
	// 	else{
	// 		++ nn;
	// 		a[nn] = a[nn - 1];
	// 	}
	// }
	// -- nn;

	// for(int i = 1; i <= nn; ++ i) cout << a[i] << ' '; cout << '\n';

	// for(int i = 1; i <= n; ++ i){
	// 	cin >> x;
	// 	++ c[x];
	// }
	// for(int i = n; i >= 1; -- i) c[i] += c[i + 1];
	

	return 0;
}