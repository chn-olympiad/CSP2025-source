#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n,m,a[110];
int R;

void dfs(int x,int y,int step,bool f)
{
	if(a[step]==R)
	{
		printf("%d %d",y,x);
		exit(0);
	}
	if((x==n&&y%2==1)||(x==1&&y%2==0)) dfs(x,y+1,step+1,f^1);
	if(f==0) dfs(x+1,y,step+1,f);
	else dfs(x-1,y,step+1,f);
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	R=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	dfs(1,1,1,0);
	return 0;
}
