#include<bits/stdc++.h>
using namespace std;
int cur = 1, cnt[11], res[1000001];
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
		if('0' <= s[i] && s[i] <= '9')
			cnt[s[i] - '0']++;
	for(int i = 9; i >= 1; i--){
		for(int j = 1; j <= cnt[i]; j++){
			res[cur++] = i;
		}
	}
	for(int i = 1; i <= cur + 1; i++) cout << res[i];
	return 0;
}

