#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[110];
int b[20][20];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=1,j=1,c=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			j=1;
			for(j=1;j<=n;j++)
			{
				b[j][i]=a[c];
				if(a[c]==t)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				c++;
			}
		}
		else
		{
			j=n;
			for(int j=n;j>=1;j--)
			{
				b[j][i]=a[c];
				if(a[c]==t)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				c++;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<b[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	return 0;
} 