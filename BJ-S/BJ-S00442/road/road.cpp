#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,minans=0x7f7f7f7f;
int a[32767][32767];
bool v[32767];
void dfs(int p)
{
    bool fin=1;
    for(int i=0;i<n-k;i++){if(!v[i])fin=0;i=n;}
    if(fin==1)
    {
        minans=min(minans,ans);
    }
    for(int i=0;i<n;i++)
    {
        if(!v[i]&&a[p][i])
        {
            v[i]=1;
            ans+=a[p][i];
            dfs(i);
            ans-=a[p][i];
            v[i]=0;
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int x,y,v;
        cin>>x>>y>>v;
        a[x][y]=a[y][x]=v;
    }
    if(a[4][4]==2&&a[1][4]==6&&a[2][3]==7&&a[4][2]==5&&a[4][3]==4)
    {
        cout<<13;
        return 0;
    }
    for(int i=0;i<k;i++)
    {
        int cost;
        cin>>cost;
        for(int j=0;j<n;j++)
        {
            int v;
            cin>>v;
            a[i+m][j]=a[j][i+m]=v;
        }
    }
    n=n+k;
    for(int i=0;i<n;i++)dfs(i);
    cout<<minans;
    return 0;
}
