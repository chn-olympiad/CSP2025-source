#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int zhu=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1;
	int y=1;
	int b[15][15];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i%2==1)
			{
				int p=(i-1)*n+j;
				b[i][j]=a[p];
			}
			else
			{
				int p=n*i-j+1;
				b[i][j]=a[p];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[j][i]==zhu)
			{
				cout<<j<<" "<<i<<endl;			
			}
		}
	}
	return 0;
}
