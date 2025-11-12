#include <bits/stdc++.h>
using namespace std;
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(long long i=0;i<s.length();i++)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			long long x = s[i]-'0';
			a[x]++;
		}
	}
	string ans;
	for(int i=9;i>=0;i--)
	{
		while(a[i])
		{
			char h = i +'0';
			ans+=h;
			a[i]--;
		}
	}
	cout << ans;
	return 0;
}
