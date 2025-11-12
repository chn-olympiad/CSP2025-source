#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int a[m+1][4],b[k+1];
    for(int i=1;i<=m;i++)
    {
        for(int u=0;u<=3;u++)
        {
            cin>>a[i][u];
        }
    }
    for(int u=0;u<k;u++)
    {
        for(int i=0;i<=k;i++)
        {
            cin>>b[i];
        }
    }
    return 0;
}
