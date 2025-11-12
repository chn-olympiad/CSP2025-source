#include<bits/stdc++.h>
using namespace std;
int n,m,a[121],t[11][11],pos;
bool cmp(int x,int y)
{
	return x>y;
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
	pos=a[1];
	sort(a+1,a+n*m+1,cmp);
	int tmp=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				t[j][i]=a[tmp];
				tmp++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				t[j][i]=a[tmp];
				tmp++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(t[i][j]==pos)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
