#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[10];
	for (int i=0;i<=10;i++)
	{
		a[i] = 0;
	}
	cin >> s;
	for (int i=0;i<s.size();i++)
	{
		char t=s[i];
		if (t>='0'&&t<='9')
		{
			a[t-'0']++;
		}
	}
	string ans;
	for (int i =9;i>=0;i--)
	{
		string str(a[i],char('0'+i));
		ans = ans + str;
	}
	cout << ans;
	return 0;
}
