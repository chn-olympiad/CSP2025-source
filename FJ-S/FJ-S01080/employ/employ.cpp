#include <bits/stdc++.h>
using namespace std;
int c[105];
long long md = 998244353;
int main(){
	freopen ("employ.in" , "r" , stdin);
	freopen ("employ.out" , "w" , stdout);
	int n , m; 
	cin >> n >> m;
	string s;
	cin >> s;
	int l = s.size();
	bool flag = 1;
	for (int i = 0 ; i < l ; i++){
		if (s[i] != '1') flag = 0;
	}
	for (int i = 1 ; i <= n ; i++){
		cin >> c[i];
	}
	sort (c + 1 , c + n + 1);
	if (flag){
		long long cnt = 1;
		for (int i = 2 ; i <= n ; i ++){
			cnt = cnt % md * i % md;
		}
		cout << cnt % md ;
		return 0;
	} 
	
	return 0;
} 
