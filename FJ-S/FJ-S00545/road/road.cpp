#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
int ans=0;
struct node{
	int u,v,w;
}a[N];
int en[N][N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);	
	}
	int t=0;
	for(int i=1;i<=k;i++)
	{
	    for(int j=1;j<=m+1;j++)
	    {
	    	scanf("%d",&en[i][j]);
		}
	}
    for(int i=1;i<=k;i++)
    {
    	ans+=a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=m;j++)
   		 {
   	 		ans+=en[i][j];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
