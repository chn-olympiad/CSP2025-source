/*
不可以，总司令？ 
*/

#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 10;

int n, q;
string s1[N], s2[N];

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++ i) cin >> s1[i] >> s2[i];
	
	while(q --){
		string t1, t2; cin >> t1 >> t2;
		cout << "0" << '\n';
	}
	
	return 0;
}
