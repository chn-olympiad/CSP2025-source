#include <bits/stdc++.h>
using namespace std; 
map<string,string> a;
bool onlyhave_a_and_b_(string s){
	for(int i = 1 ; i <= s.size() ; i++){
		if(s[i] != 'a' && s[i] != 'b') return false;
	}
	return true;
}
void solve(){
	int n,q;
	cin >> n >> q;
	string s1,s2;
	bool flag = true;
	for(int i = 1 ; i <= n ; i++ ){
		cin >> s1 >> s2;
		a[s1] = s2;
		if((!onlyhave_a_and_b_(s1)) || (!onlyhave_a_and_b_(s2))) flag = false;
	}
	if(flag){
		while(q--){
			string t1,t2;
			cin >> t1 >> t2;
			s1 = t1;
			s2 = a[t1];
			if(!onlyhave_a_and_b_(t2)){
				cout << 0 << endl;
				continue;
			}
			int cnt = 0;
			if(s1 == t2) cnt++;
			cout << cnt;
		}
		return;
	}
	while(q--){
		cout << 0 << endl;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
