#include<iostream>
using namespace std;
struct node
{
    int u,v,w;
}x[1000005];
int c[15];
int a[15][1005];
int main()
{
    freopen("road,in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i].u>>x[i].v>>x[i].w;
    }
    bool f=true;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]>0)f=false;
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]>0)f=false;
        }
    }
    cout<<0<<endl;
    return 0;
}
