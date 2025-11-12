#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int m,n,k;
    cin>>n>>m>>k;
    int a[n][3]={};
    int c[k][n+1]={};
    for(int i=0;i<n;i++)
    {
        for(int x=0;x<3;x++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            cin>>c[i][j];
        }
    }
    int ff[k]={};
    for(int i=0;i<k;i++)
    {
        ff[i]=c[i][n]
    }
    sort(ff+0,ff+k);
    cout<<ff[0];
    return 0;
}