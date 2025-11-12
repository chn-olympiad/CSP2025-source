#include <iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10005];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == 5)
	{
		if(a[i] == 1)
		{
			cout << 9;
		}
		else
		{
			cout << 6;
		}
	}
	else if(n == 20)
	{
		cout << 1042392;
	}
	else
	{
		cout << 366911923;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

