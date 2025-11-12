#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0,nh,nm,j=1;
void dfs(int x,int h,int m)
{
    h+=x;
    if(x>m)
    {
        m=x;
    }
    if(h>2*m)
    {
        sum++;
        dfs(a[j++],h,m);
    }
    else
    {
        return;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(a[1],a[1],a[1]);
    cout<<sum;
    return 0;
}
