#include<bits/stdc++.h>
#define ll long long


using namespace std;

const int N=20;
int n,m;
int a[N][N];
int v[N];
int s=0;

int main()
{
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n*m;++i)
	{
		scanf("%d",&v[i]);
	}
	
	s=v[1];
	
	sort(v+1,v+n*m+1);
	
	int nw=n*m;
	int x=1,y=1;
	
	int z=1;
	
	while(y<=m)
	{
		a[x][y]=v[nw];
		nw--;
		
		if(a[x][y]==s)
		{
			printf("%d %d",y,x);
			return 0;
		}
		
		if(x==1&&z==-1)
		{
			++y;
			z=1;
		}
		else if(x==n&&z==1)
		{
			++y;
			z=-1;
		}
		else
		{
			x+=z;
		}
	}
	
	return 0;
}
