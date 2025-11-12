#include <bits/stdc++.h>
using namespace std;
int sum[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			sum[s[i]-'0']++;
		}
	}
	string s1="";
	for(int i=9;i>=0;i--)
	{
		while(sum[i])
		{
			sum[i]--;
			s1=s1+char(i+'0');
		}
	}
	cout << s1;
	return 0;
}