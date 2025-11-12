#include<bits/stdc++.h>
using namespace std;
long long a[510],b[510],N=998244353;
long long jc(long long n)
{
    long long sum=1;
    for(long long i=1;i<=n;i++)
    {
        sum*=i;
    }
    return sum;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m,q=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        char x;
        cin>>x;
        if(x=='1') q++;
        a[i]=x-'0';
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    if(q==n)
    {
        cout<<(jc(n)/jc(m)/jc(n-m))%N;
    }
    return 0;
}
