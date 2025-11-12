#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n,k,cnt = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(k == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 0)
				cnt++;
		}
	}
	if(k == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 1)
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}
