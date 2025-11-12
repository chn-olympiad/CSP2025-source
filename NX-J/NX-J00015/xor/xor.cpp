#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    long long gun[n];
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>gun[i];
    }
    sort(gun+1,gun+n+1);
    long long z[n];
    z[0]=0;
    z[1]=gun[1];
    for(int i=2;i<=n;i++)
    {
        z[i]=z[i-1]+gun[i];
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            long long sum=z[j]-z[j-i];
            if(sum>gun[j]*2)
            {
                ans++;
            }
        }
    }
    long long num=ans%998244353;
    cout<<num;
    return 0;
}
