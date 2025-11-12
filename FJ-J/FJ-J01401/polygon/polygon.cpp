#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin >> n;
	int a[n+1] = {0};
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int cnt = 0;
	for(int i = 3;i<=n;i++)
	{
		int m = i;
		for(int jjj = 1;jjj<=m;jjj++)
		{
			for(int jj = 2;jj<=m;jj++)
			{
				for(int j = 3;j<=m;j++)
				{
					if(a[jjj]+ a[jj]>2*a[j])
					{
						cnt++;
					}
				}
			}
		}
		
	}
	cout << cnt;
	return 0;
}

