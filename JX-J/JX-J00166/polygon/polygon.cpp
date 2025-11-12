#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
bool cmp(int x,int y)
{
    return x>y;
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
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<(1<<n);i++)
    {
        int maxn=0,sum=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                maxn=max(maxn,a[j+1]);
                sum+=a[j+1];
            }
        }
        if(sum>2*maxn)
            ans++;
        if(ans>=998244353)
            ans%=998244353;
    }
    cout<<ans;
    /*for(int i=1;i+2<=n;i++)
    {
        int x=a[i];
        for(int j=i+1;j+1<=n;j++)
        {
            x+=a[j];
            for(int k=j+1;k<=n;k++)
            {
                x+=a[k];
                int dx=0;
                if(x>2*a[i])
                {
                    ans+=pow(2,n-k);
                }
                else
                {
                    check(k+1,a[i],x);
                }
                x-=a[k];
            }
            x-=a[j];
        }
    }*/
    return 0;
}
