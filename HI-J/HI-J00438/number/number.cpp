#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int sum = 0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s;
	cin >> s;
	for(int i = 1;i <= s;i++)
	{
		if (s > 0)
		{
			sum++;
		}
		else
		{
			cout << a[N] << endl;//jy
		}
	}
	return 0;
}
