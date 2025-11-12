#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],x=1,maxn;
struct qj{
    int l;
    int r;
}ans[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int cnt=0;
            for(int k=i;k<=j;k++)
            {
                cnt=cnt^a[k];
            }
            if(cnt==m)
            {
                ans[x].l=i;
                ans[x].r=j;
                x++;
            }
        }
    }
    for(int i=1;i<x;i++)
    {
        if(ans[i].l<ans[i+1].l)
            maxn++;
    }
    cout<<maxn;
    return 0;
}
