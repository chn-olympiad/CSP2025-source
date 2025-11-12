#include <bits/stdc++.h>
using namespace std;
string s;
int a[1111111] = {0};
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int ans = 0;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[i] = s[i] - '0';
			ans++;
		}
	}
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < s.size(); j++){
			if(a[j] < a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}
	for(int i = 0; i < ans; i++){
		cout << a[i];
	}
	return 0;
} 
