#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 2e5 + 5;
int n,q;
string s1[N],s2[N];
int lb1[N],lb2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> q;
	if(n > 200 || q > 200){
		for(int i = 1;i <= n;i++){
			cin >> s1[i] >> s2[i];
			for(int j = 0;j < s1[i].size();j++){
				if(s1[i][j] == 'b'){
					lb1[i] = j;
					break;
				} 
			}
			for(int j = 0;j < s2[i].size();j++){
				if(s2[i][j] == 'b'){
					lb2[i] = j;
					break;
				} 
			}
		}
		while(q--){
			int ans = 0;
			string s,ss;
			cin >> s >> ss;
			int k1,k2;
			for(int j = 0;j < s.size();j++){
				if(s[j] == 'b'){
					k1 = j;
					break;
				} 
			}
			for(int j = 0;j < ss.size();j++){
				if(ss[j] == 'b'){
					k2 = j;
					break;
				} 
			}
			for(int i = 1;i <= n;i++){
				if(k2 - k1 == lb2[i] - lb1[i] && k1 >= lb1[i] && s.size() - k1 - 1 >= s1[i].size() - lb1[i] - 1){
					ans++;
				}
			}
			cout << ans << endl;
		}
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
	}
	while(q--){
		int ans = 0;
		string s,ss;
		cin >> s >> ss;
		int l = -1,r = -1;
		for(int i = 0;i < s.size();i++){
			if(l == -1 && s[i] != ss[i]){
				l = i;
			}
			if(s[i] != ss[i]){
				r = i;
			}
		}
		for(int i = 0;i < s.size();i++){
			for(int j = 1;j <= n;j++){
				if(i + s1[j].size() - 1 >= s.size()){
					continue;
				}
				if((s1[j] == s.substr(i,s1[j].size()) && s2[j] == ss.substr(i,s1[j].size()) && i <= l && i + s1[j].size() - 1 >= r ) || (l == r && l == -1 && s1[j] == s2[j])){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
