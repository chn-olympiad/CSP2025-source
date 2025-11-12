#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int cnt[N];
int solve(){
	string s;
	cin >> s;
	for (int i = 0 ; i < s.size() ; i++ ){
		if (s[i] >= '0' && s[i] <= '9') cnt[s[i] - '0']++;
	}
	string ans = "";
	for(int i = 9 ; i >= 0 ; i-- ){
		for(int j = 1 ; j <= cnt[i] ; j++ ) ans += (char)(i + '0');
	}
	cout << ans;
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
