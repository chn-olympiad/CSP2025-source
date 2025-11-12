#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[15];
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	for(int i = 0; i < s.size(); i++){
		if(s[i] <= '9' && s[i] >= '0') a[s[i] - '0']++;
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= a[i]; j++){
			cout << i;
		}
	}
	   return 0;
}

