#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	int n,m,k,sum;
	scanf("%d %d %d",&n,&m,&k);
	int a[n+k][n+k];
	memset(a,0,sizeof(a));
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		a[u][v]=w;
		sum+=w;
	}
	printf("%d",sum);
	return 0;
}
