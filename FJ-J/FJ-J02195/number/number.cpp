#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int p = s.length();
	for(int i = 0; i < p; i++){
		if(int(s[i]) < 58)a[int(s[i]) - 48]++;
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= a[i]; j++)
			cout << i;
	}	
	return 0;
} 
