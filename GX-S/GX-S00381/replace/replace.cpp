#include <bits/stdc++.h>
using namespace std;
string m[200020][2];
int n, q;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)cin >> m[i][0] >> m[i][1];
	while(q--){
		string t1, t2;
		cin >> t1 >> t2;
		int len1 = t1.size(), len2 = t2.size();
		for(int i = 0; i <= len1; i++){
			if(t1[i] == t2[1]){
				for(int j = 0; j <= len2; j++)
			}
		}
		cout << 0 << "\n";
	}
	return 0;
}
