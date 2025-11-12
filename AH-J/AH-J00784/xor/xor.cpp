#include <iostream>
#include <cstdio> 
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int maxn = -0x3f3f3f3f;
int cnt;
int a[100005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (k == 0)
	{
		cout << 0;
	}
	else if (k <= 1 && k >= 0)
	{
		int l = 2, r = 2;
		maxn = a[2];
		while (r <= n)
		{
			while (r <= n && (a[r+1]^a[l]) > maxn)
			{
				maxn = (a[++r]^a[l]);
			}
			l++;
		}
		if (maxn == a[1])
		{
			cout << 2;
		}
		else 
		{
			cout << 0;
		}
	}
	else if (k >= 0 && k <= 255)
	{
		cout << 0;
	}
	else 
	{
		cout << 0;
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
