#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
	return a > b;
}
bool cmpp(char i)
{
	return i >= '0' && i <= '9'; 
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	long long n = s.size(),cnt = -1,c[12];
	memset(c,0,sizeof(c));
	for (long long i = 0;i < n;i++)
	{
		if (cmpp(s[i]))
		{
			int a = s[i] - '0';
			c[a]++;
		}
	}
	for (int i = 9;i >= 0;i--)
	{
		while (c[i] > 0)
		{
			cout << i;
			c[i]--;
		}
	}
	return 0;
} 