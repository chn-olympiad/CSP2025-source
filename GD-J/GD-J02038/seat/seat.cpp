#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[10010],f[105][105],d;
bool cmp(int a,int b)
{
	return a>b;
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
	d=a[1];
	sort(a+1,a+1+n*m,cmp);
	int z=1;
	for(int i=1;i<=m;i++)
	{  
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[z]==d)
				{
					cout<<i<<' '<<j;
				}
				f[i][j]=a[z];
				z++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[z]==d)
				{
					cout<<i<<' '<<j;
				}
				f[i][j]=a[z];
				z++;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
