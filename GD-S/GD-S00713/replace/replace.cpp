#include<bits/stdc++.h>
using namespace std;
int n , q;
string t1 , t2;
string s[100005][3];
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q; 
	for(int i = 1 ; i <= n ; i++){
		cin >> s[i][1] >> s[i][2];
	}
	for(int i = 1 ; i <= q ; i++){
		cin >> t1 >> t2;
		int ans = 0;
		for(int j = 1 ; j <= n ; j++){
			for(int k = 0 ; k + s[j][1].size() - 1 < t1.size() ; k++){
				if(t1.substr(k , s[j][1].size()) == s[j][1] && t2.substr(k , s[j][1].size()) == s[j][2] && t1.substr(k + s[j][1].size() , t1.size() - s[j][1].size()) == t2.substr(k + s[j][1].size() , t1.size() - s[j][1].size()) && t1.substr(0 , k) == t2.substr(0 , k)){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
