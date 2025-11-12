#include <iostream>
#include <string>
using namespace std;
const int MAXN = 2 * 1e5;
string s1[MAXN] , s2[MAXN];
string t1 , t2;
int n , q;
void solve(){
	int ans = 0;
	cin >> t1 >> t2; 
	if(t1.size() != t2.size()){
		printf("0\n");
		return;
	}
	for(int i = 1 ; i <= n ; i++){
		if(t1.size() < s1[i].size()) continue;
		int le = t1.find(s1[i]);
		if(le == t1.size()) continue;
		int gay = t2.find(s2[i]);
		if(le == gay) ans++;
	}
	cout << ans << '\n';
	return;
}
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1 ; i <= q ; i++){
		solve();
	}
	return 0;
}
