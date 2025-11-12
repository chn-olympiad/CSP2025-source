#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
string s1[N], s2[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i += 1){
		cin >> s1[i] >> s2[i];
	}
	string t1, t2;
	for(int i = 1; i <= q; i += 1){
		cin >> t1 >> t2;
		int ans = 0;
		for(int j = 1; j <= n; j += 1){
			int idx = 0;
			string str = s1[j];
			string tmp = t1;
			while(tmp.find(str, idx) != -1){
				idx = tmp.find(str, idx);
				int l = str.size();
				string tf = t1;
				string tmp2 = tf.replace(idx, l, s2[j]);
				tmp = tmp.replace(idx, l, s2[j]);
				if(tmp2 == t2) ans ++;
			}
		}
		cout << ans << '\n';
	} 
	return 0;
}

