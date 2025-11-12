#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
struct way
{
    int to;
    int val;
}a[10004];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        sum+=w;
    }
    printf("%d",sum);
}
