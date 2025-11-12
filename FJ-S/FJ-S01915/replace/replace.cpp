#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	map<string,string>mp;
	int n,q;
	cin >> n >> q;
	for(int i = 1; i <= n ;i++){
		string t1,t2;
		cin >> t1 >> t2;
		mp[t1] = t2;
	}
	for(int i = 1; i <= q; i++){
		string s1,s2;
		cin >> s1 >> s2;
		long long ans = 0;
		for(int i = 0; i < s1.size(); i++){
			for(int j = 1; i + j <= s1.size() ;j++){
				string k1 = s1.substr(i,j);
				string k2 = s2.substr(i,j);
				string x1 = s1.substr(0,i);
				string x2 = s2.substr(0,i);
				if(k1 == k2){
					continue;
				}
				if(x1 != x2){
					continue;
				}
				if(mp[k1] == k2){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

