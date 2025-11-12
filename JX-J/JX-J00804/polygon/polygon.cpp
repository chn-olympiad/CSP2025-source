#include<bits/stdc++.h>
using namespace std;
int n,m=3,b[11111],sum=0,a[11111];
void dfs(int start,int xz)
{
    if(xz==m)
    {
        int zh=0,zd=INT_MIN;
        for(int i=1;i<=m;i++)
        {
            zh+=a[i];
            zd=max(zd,a[i]);
        }
        if(zh>zd*2)
        {
            sum+=1;
        }
        return;
    }
    for(int i=start;i<=n-m+xz+1;i++)
    {
        xz+=1;
        a[xz]=b[i];
        dfs(i+1,xz);
        xz-=1;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(;m!=n;m++)
    {
        for(int i=1;i<=n-m+1;i++)
        {
            dfs(i,0);
        }
    }
    cout<<sum;
    return 0;
}
