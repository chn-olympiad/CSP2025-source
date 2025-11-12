#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000009],v[1000009],flag=0;
long long w[1000009],a[19][10009],ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    if(k<=0)
    {
        for(int i=1;i<=m;i++)
        {
            ans+=w[i];
        }
        cout<<ans;
        flag=1;
        return 0;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    long long minn=1000000009;
    for(int i=1;i<=k;i++)
    {
        minn=min(a[i][0],minn);
    }
    int dan=0;
     for(int i=1;i<=k;i++)
    {
        if(a[i][0]==minn)
        {
            dan=i;
            continue;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt+=a[dan][i];
    }
    if(flag==0)
    {
        cout<<cnt;
    }
    return 0;
}

