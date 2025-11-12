#include <bits/stdc++.h>
using namespace std;
int a[105],s[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,b;
	cin>>n>>m;
	cin>>b;
	a[1]=b;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int no=n*m+1;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				no--;
				s[j][i]=a[no];
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				no--;
				s[j][i]=a[no];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
				if(s[i][j]==b)
				{
					cout<<j<<' '<<i;
				}
		}
	}
	return 0;
}
