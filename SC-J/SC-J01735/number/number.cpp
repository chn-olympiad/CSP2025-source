// std T1
#include <bits/stdc++.h>
using namespace std;

int cnt[350];

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s; cin >> s;
	int sze = s.size();
	for(int i = 0; i < sze; i++) {
		if(s[i] >= '0' && s[i] <= '9') cnt[s[i] - '0']++;
	}
	for(int i = 9; i >= 0; i--) {
		while(cnt[i]){
			cout << i;
			cnt[i]--;
		}
	} 
	return 0;
} 
/*
J 组肯定没问题，留精力给下午 

1. long long  
2. freopen
3. linux , time ulimit size
*/