#include <bits/stdc++.h>
using namespace std;
string s;
long long one,two,the,four,five,six,seven,eight,nine,zon;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] == '0')
			zon++;
		else if(s[i] == '1')
			one++;
		else if(s[i] == '2')
			two++;
		else if(s[i] == '3')
			the++;
		else if(s[i] == '4')
			four++;
		else if(s[i] == '5')
			five++;
		else if(s[i] == '6')
			six++;
		else if(s[i] == '7')
			seven++;
		else if(s[i] == '8')
			eight++;
		else if(s[i] == '9')
			nine++;
	}
	for(int i = 1;i <= nine;i++)
		cout << 9;
	for(int i = 1;i <= eight;i++)
		cout << 8;
	for(int i = 1;i <= seven;i++)
		cout << 7;
	for(int i = 1;i <= six;i++)
		cout << 6;
	for(int i = 1;i <= five;i++)
		cout << 5;
	for(int i = 1;i <= four;i++)
		cout << 4;
	for(int i = 1;i <= the;i++)
		cout << 3;
	for(int i = 1;i <= two;i++)
		cout << 2;
	for(int i = 1;i <= one;i++)
		cout << 1;
	for(int i = 1;i <= zon;i++)
		cout << 0;
	return 0;
}
