#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cn = 0;
	cin >> s;
	for(int i = 0;i <= s.size() - 1;i++)
	{
		if(s[i] == '1')
		{
			a[i + 1] = 1;
			cn++;
		} 
		else if(s[i] == '2')
		{
			a[i + 1] = 2;
			cn++;
		} 
		else if(s[i] == '3')
		{
			a[i + 1] = 3;
			cn++;
		} 
		else if(s[i] == '4')
		{
			a[i + 1] = 4;
			cn++;
		} 
		else if(s[i] == '5')
		{
			a[i + 1] = 5;
			cn++;
		} 
		else if(s[i] == '6')
		{
			a[i + 1] = 6;
			cn++;
		} 
		else if(s[i] == '7')
		{
			a[i + 1] = 7;
			cn++;
		}
		else if(s[i] == '8')
		{
			a[i + 1] = 8;
			cn++;
		} 
		else if(s[i] == '9')
		{
			a[i + 1] = 9;
			cn++;
		} 
		else if(s[i] == '0')
		{
			a[i + 1] = 0;
			cn++;
		} 
	}
	sort(a + 1,a + s.size() + 1);
	for(int i = s.size();i > s.size() - cn;i--)
		cout << a[i];
	return 0;
}
