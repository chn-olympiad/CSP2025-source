#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int a[500005], n, k, cnt;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == k) cnt++;
		else
		{
			int sum = a[i];
			bool flag = false;
			for(int j = i + 1; j <= n; j++)
			{	
				if(flag) break;
				sum = sum ^ a[j];
				if(sum == k)
				{
					cnt++;
					i = j;
					flag = true;
				}
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
