#include <bits/stdc++.h>
using namespace std;
int a,b,sum = 0;
string s,t,c,d;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> a >> b >> c >> d;
	for (int i = 1;i <= a + b - 1;i++)
	{
		cin >> s >> t;
		if (s == c && t == d)
		{
			sum += 2;
		}
	}
	for (int i = 1;i <= b;i++)
	{
		cout << sum << endl;
		if (i == b - 1)
		{
			cout << 0;
			break;
		}
	}
	return 0;
 } 
