#include <bits/stdc++.h> 
using namespace std;
string s; 
long long max_ = 0,a[15];
int main (){
	cin >> s;
	for(int i = 0;i <= s.length();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[int(s[i] - '0')] += 1;
		}
	}
	for(int i = 10;i >= 0;i--){
		while(a[i] > 0){
			cout << i;
			a[i] -= 1;
		}
	}
	return 0;
}
