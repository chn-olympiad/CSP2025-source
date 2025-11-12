#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s , x;
	cin >> s;
	for(int i = 0;i < s.size();i++) if(isdigit(s[i])) x = x + s[i];
	for(int i = 1;i < x.size();i++){
		for(int j = 0;j < x.size() - i;j++){
			if(x[j] < x[j + 1]) swap(x[j] , x[j + 1]);
		}
	}
	cout << x;
	return 0;
} 
