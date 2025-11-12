#include <bits/stdc++.h>
using namespace std;
string s;
int len,ans[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.length();
	for(int i = 0;i < len;i++)
	{
		if(s[i] >= '0' && s[i] <= '9') ans[s[i] - '0']++;
	}
	for(int i = 9;i >= 0;i--)
	{
		if(ans[i])
		{
			for(int j = 0;j < ans[i];j++) cout << i;
		}
	}
	return 0;
}
