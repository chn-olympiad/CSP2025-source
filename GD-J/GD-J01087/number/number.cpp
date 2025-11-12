#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++){
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9){
			a[++cnt] = (int)(s[i] - '0');	
		}
	}
	for (int i = 1; i < cnt; i++){
		for (int j = 1; j < cnt; j++){
			if (a[j] < a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for (int i = 1; i <= cnt; i++){
		cout << a[i];
	}
	return 0;
	
} 
