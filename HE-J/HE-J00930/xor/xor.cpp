#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int b[n + 10];
	for(int i = 1;i <= n;i ++)
	{
		cin >> b[i];
	}
	int p = 1;
	int x[1001],y[1001];
	for(int i = 0;i <= n;i ++)
    {
        for(int j = 1;j <= n - i;j ++)
        {
        	int o = b[j];
        	for(int k = j + 1;k <= j + i;k ++)
        	{
        		o ^= b[k];
			}
			if(o == m)
			{
				x[p] = j;
				y[p] = j + i;
				p ++;
			}
		}
	}
	int o = 1;
	int u = y[1];
	for(int i = 2;i < p;i ++)
	{
		if(x[i] > u)
		{
			o ++;
			u = y[i];
		}
	}
	cout << o;
	return 0;
}
