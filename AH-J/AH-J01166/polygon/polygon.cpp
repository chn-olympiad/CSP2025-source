#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],mod=998244353;int cnt=0,x=1;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    for(int i=2;i<n;i++)
    {
        if(a[i-1]+a[i]>a[i+1]&&a[i]+a[i+1]>a[i-1]&&a[i-1]+a[i+1]>a[i])
            cnt++;
    }
    for(int i=4;i<=n;i++)
    {   int x=1;
        for(int j=n;j>=i;j--)
        {
            x*=j;
        }
        for(int j=i;j>=1;j--)
        {
            x/=i;
        }
        cnt+=x;
    }
    cout<<cnt;
    return 0;
}
