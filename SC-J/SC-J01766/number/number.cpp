#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000005],ai = 1;
	int s;
	cin >> s;
	while (s > 0)
	{
		a[ai] = s % 10;
		ai++;
		s /= 10;
	}
	sort(a + 1,a + ai);
	for (int i = ai - 1;i >= 1;i--)
	{
		cout << a[i];
	}
	return 0;
}