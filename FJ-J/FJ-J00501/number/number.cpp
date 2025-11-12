#include <iostream>
using namespace std;

int cnt[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i=0;i<s.length();i++)
	{
		if ('0'<=s[i]&&s[i]<='9')
		{
			cnt[s[i]-48]++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=cnt[i];j++)cout << i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
