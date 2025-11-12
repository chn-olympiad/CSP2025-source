#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a,i;
	s = a;
	cin >> s;
	if(a <= 100)
	{
		if(s[0] > s[1])
		{
			cout << s;
		}
		else
		{
			cout << s[1] << s[0];
		}
	}
	return 0;
}
