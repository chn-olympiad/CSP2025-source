#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5;
	string s1[maxn], s2[maxn];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> s1[i] >> s2[i];
		
	}
	while(q--){
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			cout << 0;
			continue;
		}
		string x, y, z;
		for(int i = 0; i < n; i++){
			
		}
	}
	return 0;
}
