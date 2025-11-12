#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			int t = int(s[i] - '0');
			a[t]++; 
		}
	}
	bool f = false;
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= a[i]; j++){
			if(i != 0 && a[i] >= 1){
				f = true;
			}
			if(i == 0 && !f){
				cout << 0;
				break;
			}	
			cout << i;
		}
	}
	return 0;
}
