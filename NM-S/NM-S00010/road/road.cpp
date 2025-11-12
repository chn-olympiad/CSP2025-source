#include <bits/stdc++.h>
using namespace std;
int a[100005]={};
int b[100005]={};
int c[100005]={};
int d[100005]={};
int e[100005]={};
int main()
{
    freopen("road.in","r","stdin");
    freopen("road.out","w","stdout");
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin<<d[i];
        for(int i=1;i<=n;i++)
        {
            cin>>e[i];
        }
    }
    int t=d[1];
    for(int i=2;i<=k;i++)
    {
        if(d[i]<d[i+1]&&d[i]<[d-1]&&d[i]<d[1])
        {
            t=d[i];
        }
        else if(d[i-1]<d[i+1]&&d[i-1]<d[1])
        {
            t=d[i-1];
        }
        else if(d[i+1]<d[1])
        {
            t=d[i+1]
        }
    }
    int h=e[1];
    for(int i=2;i<=n;i++)
    {

    }
    return 0;
}
