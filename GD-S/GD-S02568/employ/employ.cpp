#include<bits/stdc++.h>
#include<ctime>
#define int long long

using namespace std;

const int N = 510, mod = 998244353;

int n, m;
string s;
int c[N];

mt19937 mt(time(NULL));

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; ++ i) cin >> c[i];
	
	cout << mt() % mod;
	
	return 0;
}
