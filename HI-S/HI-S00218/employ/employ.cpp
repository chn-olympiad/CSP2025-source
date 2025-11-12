#include<bits/stdc++.h>
using namespace std;

const int N = 5e2 + 10;
const int mod = 998244353;

int n, m;
long long res = 1;
int c[N];
string s;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	for(int i = 1; i <= n; i++){
		res = res * i % mod;
	}
	cout << res << endl;
	return 0;
}
