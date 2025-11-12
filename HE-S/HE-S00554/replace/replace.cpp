#include <bits/stdc++.h>
using namespace std;
struct th{
	string a, b;
}s[111111];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s[i].a >> s[i].b;
	}
	while(m--){
		int ans = 0;
		string s1, s2;
		cin >> s1 >> s2;
		for(int i = 0; i < s1.size(); i++){
			for(int j = 0; j < n; j++){
				int o = 0;
				for(int k = i; k < s[j].a.size()+i; k++){
					if(s[j].a[k] == s1[k] && s[j].b[k] == s2[k]){
						o++;
					}else{
						break;
					}
				}
				int l = 0;
				if(o == s[j].a.size()){
					for(int g = 0; g <= s1.size(); g++){
						if(s1[g] == s2[g]){
							l++;
						}
					}
					if(l + o >= s1.size()){
						ans++;
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}
