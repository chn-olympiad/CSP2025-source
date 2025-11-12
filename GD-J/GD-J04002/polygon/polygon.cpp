#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,a[5005],dp[5005]; 
bool flag = 1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1)flag = 0;
	}
	if(flag)
	{
		int cul = 1,sum = 0;
		for(int i = 1;i <= n;i++)
		{
			cul *= 2;
		}
		for(int i = 1;i <= n - 1;i++)
		{
			sum += i;
		}
		cout << cul - 1 - sum - n << endl;
	}
	return 0;
}

