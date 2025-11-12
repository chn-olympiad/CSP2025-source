#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000];
int j;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	if(s.size() == 1){
		cout << s;
	}
	cout << endl;
	for(int i = 1; i <= 1; i++){
	 	if(s[i] == 1 || s[i] == 2){
		for(int j = 1; j <= 1000; j++){
			n[j] = s[i];
		}
		}else if(s[i]==3 || s[i]==4){
		for(int j = 1; j <= 1000; j++){
			n[j] = s[i];
		}
		}else if(s[i]==5 || s[i]==6){
			for(int j = 1; j <= 1000; j++){
			n[j] = s[i];
		}
		}else if(s[i]==7 || s[i]==8){
			for(int j = 1; j <= 1000; j++){
			n[j] = s[i];
		}
		}else if(s[i] == 9){
			for(int j = 1; j <= 1000; j++){
			n[j] = s[i];
		}
		}
	}
	

	return 0;
}
