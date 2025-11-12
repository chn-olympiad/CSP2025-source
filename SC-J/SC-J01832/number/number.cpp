#include <bits/stdc++.h>
using namespace std;
string s;
int num1,num2,num3,num4,num5,num6,num7,num8,num9,num0;
int main()
{
	freopen(" number.in","r",stdin);
	freopen(" number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++){
		if (s[i]=='1') num1++;
		if (s[i]=='2') num2++;
		if (s[i]=='3') num3++;
		if (s[i]=='4') num4++;
		if (s[i]=='5') num5++;
		if (s[i]=='6') num6++;
		if (s[i]=='7') num7++;
		if (s[i]=='8') num8++;
		if (s[i]=='9') num9++;
		if (s[i]=='0') num0++;
	}
	for (int i = 1;i<=num9;i++){
		cout << 9;
	}
	for (int i = 1;i<=num8;i++){
		cout << 8;
	}
	for (int i = 1;i<=num7;i++){
		cout << 7;
	}
	for (int i = 1;i<=num6;i++){
		cout << 6;
	}
	for (int i = 1;i<=num5;i++){
		cout << 5;
	}
	for (int i = 1;i<=num4;i++){
		cout << 4;
	}
	for (int i = 1;i<=num3;i++){
		cout << 3;
	}
	for (int i = 1;i<=num2;i++){
		cout << 2;
	}
	for (int i = 1;i<=num1;i++){
		cout << 1;
	}
	for (int i = 1;i<=num0;i++){
		cout << 0;
	}
	
	
}