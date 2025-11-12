#include<bits/stdc++.h>
using namespace std;
string s;
long long num1[10];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num1[s[i] - '0']++;
		}
	}
	int ok = 0;
	for(int i = 9;i >= 1;i--){
		while(num1[i] > 0){
			ok = 1;
			cout << i;
			num1[i]--;
		}
	}
	if(ok){
		while(num1[0] > 0){
			cout << 0;
			num1[0]--;
		}
	}
	else{
		cout << 0;
	}
	return 0;
}
