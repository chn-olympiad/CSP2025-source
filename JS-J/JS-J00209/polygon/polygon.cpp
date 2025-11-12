#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
bool u[5005];
int n,a[5005],ans;
bool cmp(int a,int b)
{
    return a>b;
}
void work1(int t)
{
    if(t==n+1)
    {
        int xam=-1,sum=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(u[i])
            {
                xam=max(xam,a[i]);
                sum+=a[i];
                cnt++;
            }
        }
        if(sum>2*xam&&cnt>=3)
        {
            ans++;
            ans%=mod;
        }
        return;
    }
    u[t]=1;
    work1(t+1);
    u[t]=0;
    work1(t+1);
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
    if(n<=3)
    {
        if(n<3)
        {
            cout<<0;
            return 0;
        }
        sort(a+1,a+n+1,cmp);
        if(a[2]+a[3]>a[1])
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        work1(1);
        cout<<ans%mod;
    }
    return 0;
}
