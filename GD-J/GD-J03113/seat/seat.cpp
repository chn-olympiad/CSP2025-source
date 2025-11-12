#include <iostream>
#include <algorithm>
using namespace std;
int a[505];
bool pd(const int &x,const int &y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,ans;
	cin >> n >> m;
	cin >> a[1];
	ans=a[1];
	for (i=2;i<=n*m;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n*m+1,pd);
	int ind=0;
	for (j=1;j<=m;j++)
	{
		if (j&1)
		{
			for (i=1;i<=n;i++)
			{
				ind++;
				if (a[ind]==ans)
				{
					cout << j << ' ' << i;
					return 0;
				}
			}
		}
		else
		{
			for (i=n;i>=1;i--)
			{
				ind++;
				if (a[ind]==ans)
				{
					cout << j << ' ' << i;
					return 0;
				}
			}
		}
	}
	return 0;
}
