#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int sum[10] = {0};
	for(int i = 0;i < s.size();i++){
		if(48 <= int(s[i]) && int(s[i]) <= 57){
			sum[s[i] - '0']++;
		}
	}
	//sort(v,v + v.size());
	for(int i = 9;i > 0;i--){
		for(int j = sum[i];j > 0;j--){
			cout << i;
		}
	}
	return 0;
} 
