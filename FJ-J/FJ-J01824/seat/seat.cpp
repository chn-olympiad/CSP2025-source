#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int n,m,a[1010],b[110][110],flag,pos=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)cin>>a[i];
	flag=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=m;i++)//lie
	{
		for (int j=1;j<=n;j++)//hang
		{
			if (i%2==1)b[j][i]=a[pos];
			else b[n-j+1][i]=a[pos];
			pos++;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			//cout<<b[i][j]<<' '; 
			if (b[i][j]==flag)
			{
				cout<<j<<' '<<i<<endl;
				return 0;
			}
		}
		//cout<<endl;
	}
	return 0; 
}
