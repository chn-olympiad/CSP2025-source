#include<bits/stdc++.h>
using namespace std;
string s[200005], t[200005];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s[i] >> t[i];
	}
	while(q--){
		string f, j;
		cin >> f >> j;
		int cnt = 0;
		string e = f;
		for (int i = 1; i <= n; i++){
			f = e;
			if (f.find(s[i]) != -1){
				f.replace(f.find(s[i]), s[i].size(), t[i]);
				if (f == j)cnt++; 
			}
		}
		cout << cnt << endl;
	}
	return 0;
} 
