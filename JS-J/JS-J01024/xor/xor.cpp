#include "bits/stdc++.h"
using namespace std;
int n,k,t;
int mx,mmx;
int a[500005];
int wa[25];
int wb[25];
int wc[25];
int ss[500005];
int qq[500005];
int change(int aa,int bb)
{
    int ans=1;
    while(ans<=aa&&ans<=bb)
    {
        ans*=2;
    }
    ans/=2;
    return ans;
}
int sy(int aaa,int bbb)
{
    int as=1;
    int abc=0;
    for(int i=20;aaa!=0;i--)
    {
        wa[i]=aaa%2;
        aaa/=2;
    }
    for(int i=20;bbb!=0;i--)
    {
        wb[i]=bbb%2;
        bbb/=2;
    }
    for(int i=20;i>=0;i--)
    {
        if(wa[i]!=wb[i])
        {
            wc[i]=1;
        }
    }
    for(int i=20;i>=0;i--)
    {
        if(wc[i])
        {
            abc+=as;
        }
        as*=2;
    }
    return as;
}
int en(int aas,int bbs)
{
    int tt=change(aas,bbs);
    aas-=tt;
    bbs-=tt;
    return sy(aas,bbs);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    qq[2]=en(a[1],a[2]);
    for(int i=3;i<=n;i++)
    {
         qq[i]=en(qq[i-1],a[i]);
    }
    for(int i=500005;i>=1;i--)
    {
        if(qq[i]==k)
        {
            mx=i;
        }
    }
    mmx=mx;
    for(int i=mx;i<=n;i++)
    {
        if(a[i]==k)
        {
            mmx++;
        }
    }
    cout<<mmx+1;
    return 0;
}
