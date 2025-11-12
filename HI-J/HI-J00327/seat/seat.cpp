#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int sum1 = 0,last = 0,sum = 0,time = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int j = i;
		while(j != 0)
		{
			last = j % 10;
			j /= 10;
			if(j != 0)
			{
				time++;
			}
			if(j % 10 == last)
			{
				sum1++;
			}
		}
		if(time == sum1)
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}
