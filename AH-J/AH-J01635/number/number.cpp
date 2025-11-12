#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	char c[1000005];
	int ans = 0;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			c[ans] = s[i];
			ans++;
		}
	}
	for(int i = 0; i < ans; i++){
		for(int j = 0; j < ans; j++){
			if(c[i] > c[j]){
				char t;
				t = c[j];
				c[j] = c[i];
				c[i] = t;
			}
		}
	}
	for(int i = 0; i < ans; i++){
		cout << c[i];
	}
	return 0;
}
