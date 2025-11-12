#include<bits/stdc++.h>
using namespace std;
int a[10000],n,m,c,ans[100][100],x,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>c;
	a[1]=c;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	cnt=n*m;
	for(int y=1;y<=m;y++)
	{
		if(y%2!=0)
		{
			x=0;
			while(x<n&&cnt>0)
			{
				ans[++x][y]=a[cnt],cnt--;
			}
		}
		else
		{
			x=n+1;
			while(x>1&&cnt>0)
			{
				ans[--x][y]=a[cnt],cnt--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c==ans[i][j])
			{
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
//2 2 98 99 100 97
//3 3 94 95 96 97 98 99 100 93 92
//
