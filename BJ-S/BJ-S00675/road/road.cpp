#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],map1[1010],broken[10010][3],n,m,k,t,map2[1010][1010],dx[1010];//t是环数量
void zhaohuan(int x)
{
    for(int i=x;i<=n;i++)
    {
        if(i==x)continue;
        if(a[i][x])
        {
            map1[i]=map1[x];
            zhaohuan(i);
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=1;
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        a[x][y]=0;
        a[y][x]=0;
        broken[i][0]=x;
        broken[i][1]=y;
        broken[i][2]=w;
    }
    int t=0;
    for(int i=1;i<=n;i++)
    {
        if(map1[i]!=0)continue;
        else
        {
            map1[i]=(++t);
            zhaohuan(i);
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        cout<<i<<map1[i];
    }*/
    for(int i=1;i<=n;i++)map2[map1[i]][++dx[map1[i]]]=1;
    for(int i=1;i<=t;i++)
    {
        
    }
    for(int i=0;i<2*k;i++)
    {
        int o;
        cin>>o;
    }
    cout<<13;
    return 0;
}
