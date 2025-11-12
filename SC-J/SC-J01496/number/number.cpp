#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
map <int,int> mp;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	for (int i = 1;i <= n;i++){
		if (0 <= (s[i] - '0') && (s[i] - '0') <= 9){
			mp[(s[i] - '0')]++;
		}
	}
	for (int i = 9;i >= 0;i--){
		if (!mp[i]){
			continue;
		}
		for (int j = 1;j <= mp[i];j++){
			cout << i;
		}
	}
	cout << "\n";
	return 0;
}
/*
290es1q0
*/