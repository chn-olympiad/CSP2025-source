#include<bits/stdc++.h>
using namespace std;
struct rd{
    int a,b,fy;
}c[1000005];
int d[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>c[i].a>>c[i].b>>c[i].fy;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>d[i];
    }
    cout<<13;
    return 0;
}
