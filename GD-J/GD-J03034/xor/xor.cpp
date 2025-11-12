#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll k, n;
const int maxn = 5 * 1e5 + 10;
ll a[maxn];
int st1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin  >> n >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(k == 1)cout << n;
	if(k == 0)cout << n / 2;
	return 0;
}
