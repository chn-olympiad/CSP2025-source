#include<bits/stdc++.h>
using namespace std;
struct str{
	string s1,s2;
};
struct str s[1000005];
int n,q;
bool intostr(string t,string s,int p){
	for(int i = 0;i < s.size();i++){
		if(t[p + i] != s[i]){
			return false;
		}
	}
	return true;
}
string jh(string str1,string str2,int p){
	string t = str1;
	for(int i = 0;i < str2.size();i++){
		t[p + i] = str2[i];
	}
	return t;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s[i].s1 >> s[i].s2;
	}
	while(q--){
		int su = 0;
		string t1,t2;
		cin >> t1 >> t2;
		for(int i = 1;i <= n;i++){
			string tt = s[i].s1;
			for(int j = 0;j < t1.size() - tt.size() + 1;j++){
				if(intostr(t1,tt,j)){
					string a = jh(t1,s[i].s2,j);
					if(a == t2){
						su++;
					}
				}
			}
		}
		cout << su << '\n';
	}
	return 0;
}

