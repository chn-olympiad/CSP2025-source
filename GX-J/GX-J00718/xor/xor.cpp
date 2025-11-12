#include <iostream>
using namespace std;
int n,k,a[500005];
int main()
{
	cin >> n >> k;
	int cnt0 = 0,cnt1 = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] == 0)
		{
			cnt0++;
		}
		if(a[i] == 1)
		{
			cnt1++;
		}
	}
	if(k == 0)
	{
		cout << cnt0;
	}
	if(k == 1)
	{
		cout << cnt1;
	}
	return 0;
}
