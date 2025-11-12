#include<bits/stdc++.h>
using namespace std;
//RP++
//I L ASCII(728383) F
const int N = 500 + 10, p = 998244353;
int n, m, c[N];
long long ans = 1;
string s;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++){
		cin >> c[i];
		
	}
	for(int i = n; i >= 1; i--)
		ans = ans * i % p;
	cout << ans;
	return 0;
}
