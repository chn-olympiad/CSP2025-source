#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using LL = long long;

int n, m, lc, c[N];
char s[N];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> s[i];
	for(int i = 1; i <= m; ++i) cin >> c[i];
	
	sort(c + 1, c + 1 + m);
	
	if(m == n){
		LL p = 1;
		for(int i = 1; i <= n; ++i){
			if(s[i] == '0'){
				cout << 0;
				return 0;
			}
		}
		for(int i = 1; i <= n; ++i){
			p *= i;
		}
		cout << p;
	}
	return 0;
}
