#include<bits/stdc++.h>
using namespace std;
string s;
int c[10];
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	int l = s.size();
	for(int i = 0 ; i < l ; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			c[s[i] - '0']++;
		}
	}
	for(int i = 9 ; i >= 0 ; i--){
		if(c[i]){
			for(int j = 1 ; j <= c[i] ; j++){
				cout << i;
			}
		}
	}
	return 0;
}
