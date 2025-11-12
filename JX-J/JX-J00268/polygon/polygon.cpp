#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<3)
    {
        cout<<0;
    }
    if(n==3)
    {
        if(max(max(a[1],a[2]),a[3])*2>a[1]+a[2]+a[3])
        {
            cout<<0;
        }
        else
        {
            cout<<1;
        }
    }
    else if(n>3)
    {
        int wei=2;
        while(wei<=n)
        {
        for(int i=wei;i<=n;i++)
        {
            int maxn=-1,sum=0;
            for(int j=1;j<=wei;j++)
            {
                sum=sum+a[j];
                maxn=max(maxn,a[j]);
            }
            sum+=a[i];
            maxn=max(maxn,a[i]);
            if(sum>maxn*2)
            {
                ans++;
            }
        }
        wei++;
        }
        cout<<ans%998244353;
    }
    return 0;
}
