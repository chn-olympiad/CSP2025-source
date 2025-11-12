#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[101] = {},cnt = 0;
	int n,m,k;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		cnt++;
	}
	k = a[1];
	sort(a + 1,a + cnt ,cmp);
	for(int i = 1;i <= cnt;i++)
	{
		if(a[i] == k)
		{
			if(i % n == 0)
			{
				if((i / n) % 2 == 0)
				{
					cout << i / n << " "<< 1;
					break;
				}
				else if((i / n) % 2 == 1)
				{
					cout << i / n << " "<< n;
					break;
				}
			}
			else
			{
				if((i / n + 1) % 2 == 0)
				{
					cout << i / n + 1 << " " << n - (i % n);
					break;
				}	
				else if((i / n + 1) % 2 == 1)
				{
					cout << i / n + 1 << " " << i % n;
					break;
				}
			
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 