#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[1002300];
	int top = 0;
	for (int i = 0;i < s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[++top] = (s[i]-48);
		}
	}
	sort(a+1,a+top+1);
	for (int i = top;i >= 1;i--)
	{
		cout <<a[i];
	}
	return 0;
} 
