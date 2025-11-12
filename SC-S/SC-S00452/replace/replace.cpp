#include<bits/stdc++.h>
using namespace std;
int n, q;
map<string, string>mp;
map<int, string>mm;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s, ss;
		cin >> s >> ss;
		mm[i] = s;
		mp[s] = ss; mp[ss] = s;
	}
	while(q--){
		string a, b;
		cin >> a >> b;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			string s = mm[i];
			string ss = mp[s];
			if(a.size() >= s.size())
			for(int j = 0; j <= a.size() - s.size(); j++){
				int flag1 = 1, flag2 = 0;
				for(int k = 0; k < s.size(); k++){
					if(a[j+k] != s[k] || b[j+k] != ss[k]){
						flag1 = 0;
					}
//					if(a[j+k] != ss[k] || b[j+k] != s[k]){
//						flag2 = 0;
//						//cout << s << " " << ss << " "
//					}
					if(!flag1 && !flag2)break;
				}
				if(flag1 == 1 || flag2 == 1){
					ans++;
					for(int k = j+s.size(); k <= n; k++){
						if(a[k] != b[k]){
							//cout << k << endl; 
							ans--;
							break;
						}
					}
					break;
				}
				if(a[j] != b[j])break;
			}
			
		}
		cout << ans << endl;
	}
	return 0;
}