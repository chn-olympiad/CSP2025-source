#include <bits/stdc++.h>
using namespace std;
int n,m,r; 
int a[105];
bool cmp(int i,int b)
{
	if(i < b)
	{
		return false;
	}
	else
		return true;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 0;i < m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(a[i*n+j] == r)
			{
				if(i%2 == 0)
				{
					cout << i+1 << " " << j;
				}
				else
				{
					cout << i+1 << " " << n-j+1;
				}
				break;
			}
		}
	}
	return 0;
}
