#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int y=a[1];
	int l=1;
	sort(a+1,a+n*m+1);
	for(int i=m;i>=1;i--)
	{
		if(i%2!=0)
		{
			for(int j=n;j>=1;j--)
			{
				b[i][j]=a[l];
			
				l++;
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				b[j][i]=a[l];
				l++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==y)
			{
				cout<<i<<" "<<j<<endl;
				break;	
			}
		}
	}
	return 0;
}
