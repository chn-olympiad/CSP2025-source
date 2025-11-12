#include<bits/stdc++.h>

using namespace std;
bool mycmp(int a,int b)
{
    return a>b;
}
int n,a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==3)
    {

        sort(a+1,a+1+n,mycmp );
        int sum=a[1]+a[2]+a[3];
        if(sum>a[1]*2)cout<<1;
        else cout<<0;
    }
    else{
        long long cnt=0;
        for(int i=3;i<=n/2;i++)
        {
            long long ans=1;
            for(int j=n,k=i;k>0;k--,j--)
            {
                ans*=j;
                ans=ans%998244353;
            }
            for(int j=2;j<=i;j++)
            {
                ans/=j;
            }
            cnt+=ans;
            cnt=cnt%998244353;
        }
        cnt*=2;
        cnt+=1;
        if(n%2==0)
        {
            long long ans=1;
            for(int i=1,j=n;i<=n/2;i++,j--)
            {
                ans=ans*j/i;
                ans=ans%998244353;
            }
            cnt-=ans;
            cnt=cnt%998244353;
        }
        cnt+=(n-1)*n/2;
        cout<<cnt;
    }
    return 0;
}
