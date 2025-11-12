#include<iostream>
using namespace std;
int n,a[100005][5],ans;
void dfs(int xx,int yy,int x,int y,int z)
{
	if(xx==n)
	{
		int x1=0,x2=0,x3=0;
		if(x<n/2)
		{
			x1=a[xx][1];
		}
		if(y<n/2)
		{
			x2=a[xx][2];
		}
		if(z<n/2)
		{
			x3=a[xx][3];
		}
		ans=max(ans,yy+max(x1,max(x2,x3)));
		return;
	}
	if(x<n/2)
	{
		dfs(xx+1,yy+a[xx][1],x+1,y,z);
	}
	if(y<n/2)
	{
		dfs(xx+1,yy+a[xx][2],x,y+1,z);
	}
	if(z<n/2)
	{
		dfs(xx+1,yy+a[xx][3],x,y,z+1);
	}
}
int main()
{
	int t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
