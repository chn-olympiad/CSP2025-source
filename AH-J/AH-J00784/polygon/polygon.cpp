#include <iostream>
#include <cstdio> 
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int a[5005];
const int mod = 998244353;
int cnt;

bool f (int x, int y, int z)
{
	return x+y+z > max(x,max(y,z))*2;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			for (int k = j+1; k <= n; k++)
			{
				if (f(i,j,k))
				{
					cnt++;
					cnt %= 998244353;
					cout << i << " " << j << " " << k << " " << endl;
				}
			}
		}
	}
	cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
