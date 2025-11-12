#include <bits/stdc++.h>
using namespace std;
string s,a;
int b[11],ans1,ans2,ans3,ans4,ans5,ans6,ans7,ans8,ans9,ans0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i<s.length();i++){
		if(s[i]=='1'){
			b[1]++;
			ans1++;
		}
		if(s[i]=='2'){
			b[2]++;
			ans2++;
		}
		if(s[i]=='3'){
			b[3]++;
			ans3++;
		}
		if(s[i]=='4'){
			b[4]++;
			ans4++;
		}
		if(s[i] == '5'){
			b[5]++;
			ans5++;
		}
		if(s[i]=='6'){
			b[6]++;
			ans6++;
		}
		if(s[i]=='7'){
			b[7]++;
			ans7++;
		}
		if(s[i]=='8'){
			b[8]++;
			ans8++;
		}
		if(s[i]=='9'){
			b[9]++;
			ans9++;
		}
		if(s[i]=='0'){
			b[0]++;
			ans0++;
		}
	}
	
	for(int i = 1;i<=ans9;i++){
		a+='9';
	}
	for(int i = 1;i<=ans8;i++){
		a+='8';
	}
	for(int i = 1;i<=ans7;i++){
		a+='7';
	}
	for(int i = 1;i<=ans6;i++){
		a+='6';
	}
	for(int i = 1;i<=ans5;i++){
		a+='5';
	}
	for(int i = 1;i<=ans4;i++){
		a+='4';
	}
	for(int i = 1;i<=ans3;i++){
		a+='3';
	}
	for(int i = 1;i<=ans2;i++){
		a+='2';
	}
	for(int i = 1;i<=ans1;i++){
		a+='1';
	}
	for(int i = 1;i<=ans0;i++){
		a+='0';
	}
	cout << a << endl;
	return 0;
}
