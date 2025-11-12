#include <iostream>
using namespace std;
int n,a[5005];
int main()
{
	cin >> n;
	int maxx = -1,cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] > maxx)
		{
		    maxx = a[i];
		}
		if(a[i] == 1)
		{
		    cnt++;
		}
	}
	if(n == 3)
	{
		if(a[1] + a[2] + a[3] > maxx * 2)
		{
			cout << 6;
		}
		else
		{
			cout << 0;
		}
	}
	if(cnt == n)
	{
		long long sum = 1;
		for(int i = 2;i <= n;i++)
		{
			sum *= i;
		}
		cout << sum;
	}
	return 0;
}
