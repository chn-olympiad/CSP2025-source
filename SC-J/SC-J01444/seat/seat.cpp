#include<bits/stdc++.h>
using namespace std;
int tx,ty,a[20],r[20][20],t,n,m;
int fx[4]={0,1,-1,0};
int fy[4]={0,0,0,1}; 
bool f[20][20];
bool cmp(int x,int y)
{
	return x>y;
}
void print(int a,int b)
{
	cout<<a<<" "<<b;
	exit(0);
}
void dfs(int x,int y,int k)
{
	r[x][y]=a[k];
	if(r[x][y]==t)
	{
		cout<<x+k-3<<" "<<y+1;
		exit(0);
	 } 
	for(int i=1;i<=3;i++)
	{
		tx=x+fx[i];
		ty=y+fy[i];
		if(tx>=1&&ty<=n&&ty>=1&&ty<=m&&f[tx][ty]==false)
		{
			f[tx][ty]=true;
			dfs(tx,ty,k+1);
			f[tx][ty]=false;
		}
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	if(k==1)
	{
		cout<<1<<' '<<1;
		return 0;
	}
	t=a[1];
	sort(a+1,a+1+n,cmp);
	dfs(1,1,1);
	return 0;
}