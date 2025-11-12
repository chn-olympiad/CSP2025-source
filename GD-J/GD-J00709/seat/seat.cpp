#include<bits/stdc++.h>
using namespace std;
int a[110];
int c[100][100];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	int cnt;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
			cnt=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int i=1;
	int ct=0;
	while(i<=n)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				ct++;
				c[i][j]==a[ct];
				if(a[ct]==cnt)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				ct++;
				c[i][j]==a[ct];
				if(a[ct]==cnt)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		i++;
	}
	return 0;
} 
