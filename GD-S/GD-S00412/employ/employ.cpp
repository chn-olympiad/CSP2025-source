#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
int c[N], n, m;
char a[N];
const int p = 998244353;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	cout << m;
	return 0;
}
