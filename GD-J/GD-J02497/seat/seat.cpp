#include<bits/stdc++.h>
using namespace std;

int a[106]; 

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n * m;i ++)
	{
		cin >> a[i];
	}
	int x = a[1];
	int t = m * n;
	sort (a + 1,a + t + 1,cmp);
//	cout << x << endl;
//	for (int i = 1;i <= n * m;i ++)
//	{
//		cout << a[i] << " ";
//	}
	int cnt = 0;
	for (int i = 1;i <= n;i ++)
	{
		for (int j = 1;j <= m;j ++)
		{
			cnt ++;
			if (a[cnt] == x)
			{
				if (i % 2 == 0)
				{
					if (cnt % m == 0) 
					{
						cout << i << " " << 1;
						return 0;
					}
					else 
					{
						cout << i << " " << m + 1 - (cnt % m);
						return 0;
					}
					
				}
				else 
				{
					if (cnt % m == 0) 
					{
						cout << i << " " << m;
						return 0;
					}
					else 
					{
						cout << i << " " << (cnt % m);
						return 0;
					}
				}
			}
		}
	}
} 
