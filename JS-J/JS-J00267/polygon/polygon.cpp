#include<bits/stdc++.h>
using namespace std;
int a[5010],n,maxn,sum;
int main()
{
    freopen(polygon.in,"r",stdin);
    freopen(polygon.out,"w",stdout);
    int type=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]!=1) type=0;
        maxn=max(a[i],maxn);
        sum+=a[i];
    }
    if(n==3)
    {
        if(sum>2*maxn) cout<<1;
    }
    if(type)
    {
        int ans=0;
        for(int i=2;i<n;i++)
        {
            ans+=n-i;
        }
        ans=ans%998%244%353;
        cout<<ans;
    }
    return 0;
}
