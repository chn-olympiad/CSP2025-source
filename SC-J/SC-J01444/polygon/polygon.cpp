#include<bits/stdc++.h>
using namespace std;
const int N=5010,K=998244353;
int n,a[N]; 
int fx[5]={0,0,1,0,-1};
int fy[5]={0,1,0,-1,0};
void print(int x,int y)
{
	cout<<x%K; 
	exit(0);
}
void dfs(int x,int y)
{
	int tx,ty;
	if(x==n&&y==n)
	{
		print(x,y);
		return ;
	}
	for(int i=1;i<=4;i++)
	{
		tx=x+fx[i];
		ty=y+fy[i];
		if(tx>=1&&tx<=n&&ty>=1&&ty<=n)
		{
			dfs(tx,ty);
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,1);
	return 0;
}