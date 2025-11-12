#include <bits/stdc++.h>
using namespace std;
const int MAXSnoSIZE = 1e6+5;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num[MAXSnoSIZE],count1 = 0;
	string s;
	cin >> s;
	for (int i = 0;i < s.size();i++){
		if(s[i] == '1') num[count1++] = 1;
		else if(s[i] == '2') num[count1++] = 2;
		else if(s[i] == '3') num[count1++] = 3;
		else if(s[i] == '4') num[count1++] = 4;
		else if(s[i] == '5') num[count1++] = 5;
		else if(s[i] == '6') num[count1++] = 6;
		else if(s[i] == '7') num[count1++] = 7;
		else if(s[i] == '8') num[count1++] = 8;
		else if(s[i] == '9') num[count1++] = 9;
		else if(s[i] == '0') num[count1++] = 0;
	}
	sort(num,num + count1+1);
	for (int i = count1;i > 0;i--){
		cout << num[i];
	}
	return 0;
}
