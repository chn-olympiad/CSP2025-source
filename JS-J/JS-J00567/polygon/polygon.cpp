#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    unsigned long long n;
    unsigned long long ans=0,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(unsigned long long i=2;i<n;i++)
    {
        for(unsigned long long j=i;j<n;j++)
        {
            ans+=(n-j)*(n-j+1)/2;
        }
    }
    b=ans%998244353;
    cout<<b;
    return 0;
}
