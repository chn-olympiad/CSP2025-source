#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    int q=1,w=1,e=0,r=0,t=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            e++;
        }
        if(a[i]==1&&a[i-1]==1&&i-1!=t)
        {
            r++;
            t=i;
        }
        if(a[i]!=1)
        {
            q=0;
        }
        if(a[i]!=1&&a[i]!=0)
        {
            w=0;
        }
    }
    if(q==1&&m==0)
    {
        cout<<n/2;
        return 0;
    }
    if(q==1&&m==1)
    {
        cout<<n;
        return 0;
    }
    if(w==1&&m==1)
    {
        cout<<e;
        return 0;
    }
    if(w==1&&m==0)
    {
        cout<<n-e+r;
        return 0;
    }
    return 0;
}
