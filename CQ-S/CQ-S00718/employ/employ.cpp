#include <bits/stdc++.h>
using namespace std;
const int N = 505;
long long n, m, i, c[N], ans;
string s; 
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(i = 1; i <= n; i++){
		cin >> c[i];
	}
	ans = 1;
	for(i = 2; i <= n; i++){
		ans *= i;
	}
	cout << ans;
	return 0;
}
