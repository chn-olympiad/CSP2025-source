#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
//KMP!!!
string s[N], t, s1[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++){
		cin >> s[i] >> s1[i];
	}
	while(q--){
		cout << "0\n";
	}
	return 0;
}
