#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int gz[1000005],gzroad[1000005];
//城市数量 道路数量 改造数量
struct node
{
    int a,b;
}road[1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {   
        scanf("%d %d %d",&road[i].a,&road[i].b,&moneyroad[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>gz[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>gzroad[i];
    }
    
    return 0;
}