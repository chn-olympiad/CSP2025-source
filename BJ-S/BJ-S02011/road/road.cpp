#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, fa[100010], u[1000010], v[1000010], w[1000010], xmin=INT_MAX;
int Find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
void marge(int x, int y)
{
    fa[Find(y)]=Find(x);
}
bool check(int mid)
{
    for(int i=1;i<=100000;i++)
        fa[i]=i;
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        if(w[i]>mid)
        {
            marge(u[i], v[i]);
            sum+=w[i];
        }
    }
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==i)
        {
            if(flag)return false;
            else
            {
                flag=true;
            }
        }
    }
    xmin=min(xmin, sum);
    return true;
}
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    bool flag=true;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            int c;
            cin>>c;
            if(c!=0)
                flag=false;
        }
    }
    if(flag&&k!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    int l=1, r=1e9;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<xmin<<endl;
    return 0;
}
/*
4 4 0
1 4 2
2 4 3
1 3 7
1 2 4
*/
/*
12
*/
