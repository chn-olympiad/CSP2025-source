#include <bits/stdc++.h>
using namespace std;
int n,cnt=0,cnt0=0,cntx=0,res=0,k;
bool fl=1;
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int u;
        cin>>u;
        if(u==0)
        {
            cntx+=(res/2);
            res=0;
        }
        cnt+=(u==1);
        cnt0+=(u==0);
        res+=(u==1);
        if(u>1)
            fl=0;
    }
    cntx+=(res/2);
    res=0;
    if(fl)
    {
        if(k==1)
            cout<<cnt;
        else
            cout<<cnt0+cntx;
    }
    else
    {
        puts("0");
    }
    return 0;
}
