#include <bits/stdc++.h>
using namespace std;

int b[105];
int a[105][105];
bool cmp (int x , int y)
{
	return x > y;
}

int main ()
{
	freopen ("seat.in" , "r" , stdin);
	freopen ("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> b[i];
	} 
	int k = b[1];
	sort (b + 1 , b + (n * m) + 1 , cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				cnt++;
				if (b[cnt] == k)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else if (i % 2 == 0)
		{
			for (int j = n; j > 0; j--)
			{
				cnt++;
				if (b[cnt] == k)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
	//#Shang4Shan3Ruo6Shui4
} 
