#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s;
	cin >> s;
	for(int i = 0;i < length();i++){
		if(s[i] = "0";s[i] <= "9"){
			num[[s][i] - "0"]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		if(num[i] = 0){
			while (num[i]){
				cout << i;
				num[i]--;
			}
		}
	}
	return 0;
}
