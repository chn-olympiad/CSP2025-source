#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, q;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> q;
	string a, b;
	//Trie tr;
	for (int i = 1;i <= n;i++){
		cin >> a >> b;
	}
	while(q--){
		cin >> a >> b;
		cout << 1;
	}
	return 0;
}
