#include<bits/stdc++.h>
using namespace std;
int vis[1000001];
int main()
{
	freopen("number.in","in",stdin);
	freopen("number.out","out",stdout);
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if('0' <= s[i] <= '9')
		{
			vis[s[i]-'0']++;
		}
	}
	string c = "";
	for(int i = 9;i >= 0;i--)
	{
		while(vis[i]!=0)
		{
			c+=i+'0';
			vis[i]--;
		}
	}
	cout << c;
	return 0;
}
