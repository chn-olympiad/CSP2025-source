#include<cstdio>
#include<iostream>
#define mod 998244353
using namespace std;

int s[5000];
int a[5000];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int m=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m=max(m,a[i]);
        s[i]=s[i-1]+a[i];
    }
    int cnt=0;
    if(m<=1)
    {
        for(int i=1;i<=n-2;i++)
        {
            for(int j=i+2;j<=n;j++)
            {
                if(s[j]-s[i-1]>2)cnt=(cnt+1)%mod;
            }
        }
        cout<<cnt;
        return 0;
    }
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+2;j<=n;j++)
        {
            int maxn=-1;
            for(int k=i;k<=j;k++)
            {
                maxn=max(maxn,a[k]);
            }
            if(s[j]-s[i-1]>maxn*2)cnt=(cnt+1)%mod;
        }
    }
    cout<<cnt;
    return 0;
}
