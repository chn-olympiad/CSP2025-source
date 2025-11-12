#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[m*n+1],b[m+1][n+1];
	for(int i=1;i<=m*n;i++)cin>>a[i];
	int qwe=a[1];
	sort(a+1,a+m*n+1);
	
	int str=0;
	int num=m*n;
	for(int i=1;i<=m;i++)
	{
		if(str==0)
		{
			for(int j=1;j<=n;j++)
			{
				b[i][j]=a[num];
				num--;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				b[i][j]=a[num];
				num--;
			}
		}
		str=1-str;
	}
	
	str=0;
	for(int i=1;i<=m;i++)
	{
		if(str==0)
		{
			for(int j=1;j<=n;j++)
			{
				if(b[i][j]==qwe)
				{
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(b[i][j]==qwe)
				{
					cout<<i<<" "<<j;
					break;
				}

			}
		}
		str=1-str;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
