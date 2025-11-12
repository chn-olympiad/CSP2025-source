#include <bits/stdc++.h>
using namespace std;
int num[1000010];
void solve(){
	string s;
	cin >> s;
	int tot = 0;
	for (char c : s){
		if ('0' <= c && c <= '9'){
			num[++tot] = c - '0';
		}
	}
	sort(num + 1, num + tot + 1);
	for (int i=tot; i>=1; i--){
		cout << num[i];
	}
} 

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while(T--){
		solve();
	}
}
