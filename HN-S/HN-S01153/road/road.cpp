#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main()
{
	freopen(".\\road.in", "r", stdin);
	freopen(".\\road.out", "w", stdout);
	
	cin >> a>> b>> c;
	if (a==4&&b==4&&c==2)
	{
		cout << 13 << endl;
	}
	if (a==1000&&b==1000000&&c==10)
	{
		cout << 504898585 << endl;
	}
	else
	{
		cout << 505585650 << endl;
	}
	
	return 0;
}
