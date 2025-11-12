#include<bits/stdc++.h>
using namespace std;
long long n,a[5555],cnt,sum;
long long f(long long n)
{
    long long sum=1;
    for(int i=1;i<=n;i++)
    {
        sum*=i;
    }
    return sum;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdin);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=3;i<=n;i++)
    {
        long long sum1=f(n-i)*f(i);
        sum+=f(n)/sum1;
    }
    cout<<sum;
    return 0;

}
