#include<iostream> 
using namespace std;
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m;
	cin >> n >> m;
	int a[n*m];
	int b=1;
	int d=100;
	for(int i=1;i<=n*m;i++)
	{
		cin >>a[i];
	}
	for(int i=1;i<=n;i++) 
	{
		if(i%2!=0)
		{
			for(int j=m;j>=1;j--)
			{
				d--;
				if(a[1]==d)
				{
					cout << i << " " << j;
				}
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				d--;
				if(a[1]==d)
				{
					cout << i << " " << j;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
