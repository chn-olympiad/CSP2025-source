#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,u,v,w,h,t,wa=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>a[i];

    }
    sort(a+1,a+m+1);
    for(int i=1;i<=k;i++)
    {
        cin>>h;
        for(int j=1;j<=n;j++)
        {
            cin>>t;
            w+=t;
        }

    }
    wa/=(k*2);
    for(int i=1;i<=m/2;i++)
    {
        wa+=a[i];
    }
    cout<<wa;

}
