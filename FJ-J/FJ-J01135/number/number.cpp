#include<bits/stdc++.h>
using namespace std;
string s;
string a;
int len = 0;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.length();
	int f[10] = {};
	for(int i = 0;i < len;i++){
		f[s[i] - '0']++;
	}
	for(int i = 9;i >= 0;i--){
		while(f[i] > 0){
			a = a + char(i + '0');
			f[i]--;
		}
	}
	cout << a;
	return 0;
}

