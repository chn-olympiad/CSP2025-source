#include <bits/stdc++.h>
#define N 1000006
using namespace std;
string s;
int tot;
int cnt[N];
int main(){
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s;
	int len = s.length();
	for (int i = 0; i <= len; i++){
		if (s[i] >= '0' && s[i] <= '9') {
			cnt[++tot] = s[i] - '0';
		}
	} 
	sort(cnt + 1, cnt + tot + 1);
	for (int i = tot; i >= 1; i--){
		cout << cnt[i];
	}
	
	return 0;
} 
