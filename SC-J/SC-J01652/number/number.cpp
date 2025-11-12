#include <bits/stdc++.h> 
using namespace std;
string s;
int a[15];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'<=9&&s[i]-'0'>=0)
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--)
	{
		while(a[i])
		{
			cout << i;
			a[i]--;
		}
	}
	return 0;
}