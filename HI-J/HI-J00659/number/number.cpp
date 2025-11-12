#include <bits/stdc++.h>
using namespace std;
string s;
long long f[10];
string sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			continue;
		}
		int a = s[i] - '0';
		f[a]++;
	}
	for (int i = 9;i >= 0;i--)
	{
		for (;f[i] > 0;f[i]--)
		{
			sum += (i + 48);
		}
	} 
	cout << sum;
	return 0;
}
