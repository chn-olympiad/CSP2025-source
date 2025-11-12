#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, v;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		 if(s[i] <= '9' && s[i] >= '0'){
		 	v += s[i];
		 }
	}
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v.size(); j++){
		 	if(v[i + 1] > v[i]){
		 		char ch = v[i];
		 		v[i] = v[i + 1];
		 		v[i + 1] = ch;
		 	}	
		}
	}
	cout << v;
	return 0;
} 
