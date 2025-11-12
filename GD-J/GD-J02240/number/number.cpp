#include<bits/stdc++.h> 
using namespace std;
int a[15], m;
char b;
string s, t;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i=0; i<s.size(); i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			m=s[i]-'0';
			a[m]++;
		}
	}
	for (int i=9; i>=0; i--)
	{
		while(a[i])
		{
			b=i+'0';
			t+=b;
			a[i]--;
		}
	}
	cout << t;
	return 0;
}
