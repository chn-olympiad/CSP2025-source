#include<iostream>
#include<algorithm>
using namespace std;
int a[105],b[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	cin>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+(n*m));
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<a[i]<<" ";
//	}
	int k=n*m;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				b[i][j]=a[k];
				k--;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				b[i][j]=a[k];
				k--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(x==b[i][j])
			{
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
