#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int n, m, ans = 0;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0; i < s.lengh(); i++){
		if(s[i] == '1'){
			ans++;
		}
	}
	cout << ans << emdl;
	return 0;
}
