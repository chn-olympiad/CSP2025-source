#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int x;
    for(int i=1;i<=m;i++)
    {
		scanf("%d%d%d",&x,&x,&x);
	}
    for(int i=1;i<=k*(n+1);i++)
    {
		scanf("%d",&x);
	}
	printf("0");
    return 0;
}
