#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n;
	int o[1000];
	n = s.size();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(s[i] >= 'a' ){
				i++;
			}else if(s[j] >= 'a' ){
				j++;
			}else{ 
				o[i] =max(s[i],s[j]);
			} 
		}
	}
	for(int i = 1; i <= n; i++){
		cout << o[i]; 
	}
	return 0;
} 
