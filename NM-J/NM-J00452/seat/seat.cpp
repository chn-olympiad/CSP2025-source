#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin >> n >> m;
	int b[m*n];
	int a[m][n];
	for (int i=0;i<m*n;i++)
	{
		cin >> b[i];
	}
	x=b[0];
	for (int i=0;i<m*n;i++)
	{
		for (int j=i;j<m*n;j++)
		{
			if (b[i]<b[j])
			{
				swap(b[i],b[j]);
			}
		}
	}
	int temp=0;
	for (int i=0;i<m;i++)
	{
		if (i%2==0)
		{
			for (int j=0;j<n;j++)
			{
				a[i][j]=b[temp];
				temp++;
			}
		}
		else if (i%2==1)
		{
			for (int j=n-1;j>=0;j--)
			{
				a[i][j]=b[temp];
				temp++;
			}
		}
	}

	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (a[i][j]==x)
			{
				cout << i+1 << " " << j+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
