#include<bits/stdc++.h>
using namespace std;
int a[5005],n,maxn=0;
long long g=0;
void dp(int m,int h,int s,int l)
{   if(m==n+1 and h>s*2 and l>=3)
    {   g=g+1;
        g%=998244353;
        return;
    }
    else if(m==n+1)
        return;
    dp(m+1,h+a[m],max(s,a[m]),l+1);
    dp(m+1,h,s,l);
}
int main()
{   freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {   cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1)
    {   int h1=0,h2=0,m=1,s=1;
        for(int i=1;i<=n;i++)
            if(a[i]==1)
                h1++;
            else
                h2++;
        for(int i=1;i<=h1;i++)
            m=(m*2)%998244353;
        m-=1+h1+h1%998244353*(h1-1)%998244353/2;
        for(int i=1;i<=h2;i++)
            s=(s*2)%998244353;
        cout<<m*s%998244353;
    }
    else
    {   dp(1,0,0,0);
        cout<<g;
    }
    return 0;
}
