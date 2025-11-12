#include<bits/stdc++.h>
using namespace std;
int n;
int ans[15];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size();
	for(int i = 0;i < len;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			ans[s[i] - '0']++;
		}
	}
	for(int i = 9;i >= 0;i--)
	{
		while(ans[i]--)
		{
			printf("%c", char(i + '0'));
		}
	}
	return 0;       
}