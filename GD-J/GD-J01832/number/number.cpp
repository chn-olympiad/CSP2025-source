/*********************
 ~AUTHOR BY "ILWF^_^"
 ~author by "ILWF^_^"
*********************/
#include<bits/stdc++.h>
#define ILW return
#define F 0
using namespace std;
using ll = long long;
const ll N = 200005;
const ll mod = 1e9 + 7;
string s;
vector<char> ve;
void solve(){
	cin >> s;
	for(auto c : s) if(c >= '0' && c <= '9') ve.push_back(c);
	sort(ve.begin() , ve.end());
	reverse(ve.begin() , ve.end());
	for(auto x : ve) cout << x;
}
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
	//cin >> t;
	while(t--) solve();
	ILW F;
}
