#include<bits/stdc++.h>
using namespace std;
int a[15], ans;
int main(){
	string s;
	cin >> s;
	for (int i = 1; i <= s.size(); i++){
		if(s[i] >= '1' && s[i] <= '9'){
			a[s[i] - '1'] ++;
		}
	}
	for (int i = 9; i >= 1; i--){
		while(a[i] > 0){
			ans = ans * 10 + a[i];
		}
	}
	cout << ans;
	cout << "111";
	return 0;
}



 
