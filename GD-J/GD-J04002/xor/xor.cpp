#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k,a[500005],flag1 = 1,flag2 = 1,cnt0,cnt1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1)
		{
			flag1 = 0;
		}
		if(a[i] != 1 && a[i] != 0)
		{
			flag2 = 0;
		}
		if(a[i] == 1)cnt1++;
		else if(a[i] == 0)cnt0++;
	}
	if(flag1)
	{
		cout << n / 2 << endl;
	}
	else if(flag2 && k == 1)
	{
		cout << cnt1 << endl;
	}
	else if(flag2 && k == 0)
	{
		cout << cnt0 + cnt1 / 2 << endl;
	}
	else if(flag2)
	{
		cout << 0 << endl;
	}
	return 0;
}

