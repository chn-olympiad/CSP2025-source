#include <bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.length();
	for(int i = 0;i < n;i++){
		if(s[i] <= '9' && s[i] >= '0'){
			a[s[i] - 48]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		if(a[i]){
			for(int j = 1;j <= a[i];j++) cout << i;
		}
	}
	return 0;
}

