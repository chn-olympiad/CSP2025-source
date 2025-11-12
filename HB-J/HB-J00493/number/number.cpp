#include <bits/stdc++.h>
using namespace std;
string s ;
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1, s2, s3, s4, s5, s6 ,s7, s8, s9, s0;
	cin >> s ;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '1')
		{
			s1 += "1";
		}
		if(s[i] == '2')
		{
			s2 += "2";
		}
		if(s[i] == '3')
		{
			s3 += "3";
		}
		if(s[i] == '4')
		{
			s4 += "4";
		}
		if(s[i] == '5')
		{
			s5 += "5";
		}
		if(s[i] == '6')
		{
			s6 += "6";
		}
		if(s[i] == '7')
		{
			s7 += "7";
		}
		if(s[i] == '8')
		{
			s8 += "8";
		}
		if(s[i] == '9')
		{
			s9 += "9";
		}
		if(s[i] == '0')
		{
			s0 += "0";
		}
	}
	cout << s9 << s8 << s7 << s6 << s5 << s4 << s3 << s2 << s1 << s0 ;
	return 0;
}
