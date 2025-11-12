#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	long long number[10];
	memset(number,0,sizeof(number));
	for(long long i = 0;i < s.length();i++)
	{
		if(s[i] - '0' >= 0 && s[i] - '0' <= 9)
		{
			number[(s[i] - '0')]++;
		}
	}
	for(int i = 9;i >= 0;i--)
	{
		for(long long j = 1;j <= number[i];j++)
			cout << i;
	}
	return 0;
}
