//T1Æ´Êý
#include <bits/stdc++.h>
using  namespace std;
int num[15], cnt;
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i=0; i<s.size(); ++i){
		if(s[i] == '0') ++num[0];
		else if(s[i] == '1') ++num[1];
		else if(s[i] == '2') ++num[2];
		else if(s[i] == '3') ++num[3];
		else if(s[i] == '4') ++num[4];
		else if(s[i] == '5') ++num[5];
		else if(s[i] == '6') ++num[6];
		else if(s[i] == '7') ++num[7];
		else if(s[i] == '8') ++num[8];
		else if(s[i] == '9') ++num[9];
	}for (int i=9; i>=0; --i){
		cnt = num[i];
		for (int j=1; j<=cnt; ++j)
			cout << i;
	}return 0;
}
