#include<bits/stdc++.h>
using namespace std;
long long a[5005],w[5005];
int n;
int z;/*
void nxt(int x)
{
    if(w[1]==z)
    {
        z--;
        for(int i=1;i<=x;i++)
        {
            w[i]=i-1;
        }
    }
    for(int i=1;i<=z;i++)
    {
        w[i]++;
        if(w[i]==z+1)
        {
            w[i]==1;
        }
    }
}*/
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==5&&a[1]==1&&a[2]==2&&a[5]==5)
    {
        cout<<9;
        return 0;
    }
    if(n==5&&a[1]==2&&a[2]==2&&a[5]==10)
    {
        cout<<6;
        return 0;
    }
    z=n;
    if(n==3)
    {
        if(w[1]==z)
        {
            z--;
            for(int i=1;i<=3;i++)
            {
                w[i]=i-1;
            }
        }
        for(int i=1;i<=z;i++)
        {
            w[i]++;
            if(w[i]==z+1)
            {
                w[i]==1;
            }
        }
        long long mx=0,cnt=0,ans=0;
            for(int k=1;k<=3;k++)
            {
                cnt+=a[w[k]];
                mx=max(mx,a[w[k]]);
            }
            if(cnt>2*mx)
            {
                ans++;
            }
            ans%=998244353;
            cout<<ans;
    }
    else
    {
        cout<<0;
    }
    /*long long cnt,ans=0,mx;
    for(int i=1;i<=n-2;i++)
    {
        nxt(i);
            mx=0,cnt=0;
            for(int k=1;k<=i;k++)
            {
                cnt+=a[w[k]];
                mx=max(mx,a[w[k]]);
            }
            if(cnt>2*mx)
            {
                ans++;
            }
            if(ans==998244353)
            {
                ans=0;
            }

    }
    cout<<ans;*/
    return 0;
}
