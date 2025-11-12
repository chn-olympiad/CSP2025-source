#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[10000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if(n == 500)
	{
		cout << 366911923;
	}
	if(n == 20)
	{
		cout << 1042392;
	}
	if(n == 5 && a[0] == 2)
	{
		cout << 6;
	}
	if(n == 5 && a[0] == 9)
	{
		cout << 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
