#include<bits/stdc++.h>
using namespace std;

string s1[105], s2[105], t1, t2;
int n, q, ans;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	}
	while(q--){
		ans = 0;
		cin >> t1 >> t2;
		for(int i = 0; i < t1.size(); i++){
			for(int j = i + 1; j < t1.size(); j++){
				string s = "";
				for(int k = i; k <= j; k++){
					s.push_back(t1[k]);
				}
				for(int k = 1; k <= n; k++){
					if(s == s1[k]){
						string t = "";
						for(int l = 0; l <= i - 1; l++) t.push_back(t1[l]);
						t = t + s2[k];
						for(int l = j + 1; l < t1.size(); l++) t.push_back(t1[l]);
						if(t == t2) ans++;
					}
					else if(s == s2[k]){
						string t;
						for(int l = 0; l <= i - 1; l++) t.push_back(t1[l]);
						t = t + s1[k];
						for(int l = j + 1; l < t1.size(); l++) t.push_back(t1[l]);
						if(t == t2) ans++;
					}
				}
			}
		} 
		cout << ans << "\n";
	}
	return 0;
} 
