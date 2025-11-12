#include<bits/stdc++.h>
using namespace std;
string s;
int number[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n = s.size();
	s = " " + s;
	for(int i = 1; i <= n; i++){
		if(s[i] >= '0' &&s[i] <= '9'){
			int temp = s[i] - '0';
			number[temp]++;
		}
	}
	for(int i = 9; i >= 0; i--){
		if(number[i]){
			for(int j = 1; j <= number[i]; j++){
				cout << i;
			}
		}
	}
	return 0;
} 
