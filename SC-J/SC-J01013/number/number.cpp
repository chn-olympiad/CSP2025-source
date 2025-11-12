#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int x = 0;
	for(int i = 0; i < s.size(); i++){
		if(48 <= s[i] && s[i] <= 57){
			a[x] = s[i] - 48;
			x++;
		}
	}
	sort(a, a+x);
	for(int i = x-1; i >= 0; i--){
		cout << a[i]; 
	}
	return 0;
} 