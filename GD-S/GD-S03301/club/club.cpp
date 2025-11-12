#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][3],b=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=3;j++)
		{
			if(a[i][j-1]<a[i][j])
			{
				b+=a[i][j];
			}
			else
			{
				b+=a[i][j-1];
			}
		}
	}
	cout<<b;
	return 0;
 } 
