#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
int n,m;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)//列数m  行数n
	{
		cin>>a[i];
	}
	int R=a[0];
	sort(a,a+m*n+1,cmp);
	int k=0;
	for(int i=1;i<=m;i++)
	{	
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				b[j][i]=a[k];
				k++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				b[j][i]=a[k];
				k++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[j][i]==R)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
} 
