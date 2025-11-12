#include <bits/stdc++.h>
using namespace std;
string s, ans;
long long a[10] = {0};
bool p = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if('0' <= s[i] && s[i] <= '9'){
			a[s[i] - '0'] ++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= a[i]; j++){
			if(i != 0)
			p = 1;
			ans += char(i + '0');
		}
	}
	if(p == 0) cout << 0;
	else cout << ans;
	return 0;
}
