#include <bits/stdc++.h>
using namespace std;

int a[5005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int temp, cnt = 0;
	for(int i=3; i<=n; i++) // 决定所用木棍数目i
	{
		for(int j=1; j<=n-i; j++)// 起始索引 
		{
			temp = 0;
			for(int k=0; k<i; k++)// 向后i根累加结果 
			{
				temp += a[j+k];
			}
			if(temp > a[j+i-1]*2)// 所有长度之和大于2倍max		
			{
				cnt += (a[j]*2+1);
				break;
			}
		}
	}
	cnt %= 998;
	cnt %= 244;
	cnt %= 353;
	cout << cnt+1;
	return 0;
}
