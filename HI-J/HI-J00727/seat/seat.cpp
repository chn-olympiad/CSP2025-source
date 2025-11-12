#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],s[15][15],x,cnt=1;
bool cmp(int b,int c)
{
	return b>c;
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
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				s[i][j]=a[cnt];
				if(a[cnt]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				s[i][j]=a[cnt];
				if(a[cnt]==x)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
} 
