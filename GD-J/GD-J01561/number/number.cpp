#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i]-'0' <= 9 && s[i] - '0' >= 0)
			a[s[i]-'0']++;
	}
	for(int i = 9;i >= 0;i--)
	{
		if(a[i] >= 1)
		{
			while(a[i]--)
			{
				cout << i;
			}
		}
	}
	return 0;
}
