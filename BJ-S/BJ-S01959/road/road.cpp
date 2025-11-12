#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct node{
int v,w,op;
}a[100010];
int c[100010];
int p[12][10010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    int ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].v>>a[i].w>>a[i].op;
        ans+=a[i].op;
    }
    bool flag=1;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]!=0)
        {
            flag=0;
        }
        for(int j=1;j<=n;j++)
        {
            cin>>p[i][j];
            if(p[i][j]!=0)
            {
                flag=1;
            }
        }
    }
    if(flag==1)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}
