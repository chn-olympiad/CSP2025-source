#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	int flag = 0;
	int a[10] = {0};
	for(int i = 0;i < s.size();i++){
		if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
			if(s[i] - '0' == 0){
				a[0] += 1;
			}
			if(s[i] - '0' == 1){
				a[1] += 1;
			}
			if(s[i] - '0' == 2){
				a[2] += 1;
			}
			if(s[i] - '0' == 3){
				a[3] += 1;
			}
			if(s[i] - '0' == 4){
				a[4] += 1;
			}
			if(s[i] - '0' == 5){
				a[5] += 1;
			}
			if(s[i] - '0' == 6){
				a[6] += 1;
			}
			if(s[i] - '0' == 7){
				a[7] += 1;
			}
			if(s[i] - '0' == 8){
				a[8] += 1;
			}
			if(s[i] - '0' == 9){
				a[9] += 1;
			}
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 0;j < a[i];j++){
			cout << i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
