#include <bits/stdc++.h>
using namespace std;
string s1[200005], s2[200005];
int l, r;
void check(string x, string y){
	l = r = -1;
	for(int i = 0; i <= x.length() - y.length(); i++){
		if(x[i] == y[0]){
			int ff = 1;
			for(int j = 0; j < y.length(); j++){
				if(x[i + j] != y[j]){
					ff = 0;
					break;
				}
			}
			if(ff == 1){
				l = i;
				r = i + y.length() - 1;
				break;
			}
		}
	}
	return ;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	}
	while(q--){
		string t1, t2;
		cin >> t1 >> t2;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(s1[i].length() > t1.length()){
				continue;
			}
			check(t1, s1[i]);
			if(l != -1){
				string flag = "";
				for(int j = 0; j < l; j++){
					flag += t1[j];
				}
				flag += s2[i];
				for(int j = r + 1; j < t1.length(); j++){
					flag += t1[j];
				}
				if(flag == t2){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
