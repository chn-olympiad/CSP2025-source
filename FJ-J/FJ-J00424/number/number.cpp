#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	int ui[11] = {};
	int i = -1;
	cin >> str;
	while(str[++i]){
		if(str[i] >= 48 && str[i] <= 57){
			ui[str[i]-48]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		while(ui[i]--){
			cout << i;
		}
	}
	return 0;
} 
