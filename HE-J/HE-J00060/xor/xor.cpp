#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k, x = 0;
	cin >> n >> k;
	int a[n + 10];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		
		for(int j = 1;j <= n - i;j++)
		{
			int b = a[j];
			for(int k = j + 1;k <= j + i;k++)
			{
				b = b ^ a[k];
			}
			if(b == k)
				x++; 
		}
	}
	cout << x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
