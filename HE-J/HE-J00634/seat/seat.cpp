#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[105],mp[15][15];
bool find()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==0)
			{
				return 1;
			}
		}
	}return 0;
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];	
	}
	int nm=n*m;
	int sum=a[1];
	sort(a+1,a+1+nm,cmp);
	int x=1,y=1,cnt=0;	
	while(find())
	{
		mp[x][y]=1;
		if(y%2)
		{
			while(x<=n)
			{
				mp[x][y]=a[++cnt];
				if(mp[x][y]==sum)
				{
					cout<<y<<" "<<x;
					return 0;
				}
				x++;
			}x--;y++;
		}else{
			while(x>=1)
			{
				mp[x][y]=a[++cnt];
				if(mp[x][y]==sum)
				{
					cout<<y<<" "<<x;
					return 0;
				}
				x--;
			}x++;y++;
		}
	}
	return 0;
}/*


3 3 
94 95 96 97 98 99 100 93 92*/

