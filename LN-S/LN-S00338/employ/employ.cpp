#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long t[501];
bool f;
long long b;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    char s[501];
    long long c[501];
    for(long long i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(long long i=1;i<=n;i++)
    {

        cin>>c[i];
    }
    for(long long i=1;i<=n;i++)
    {
        if(s[i]=='0')
        {
            t[i]=0;
        }
        else
        {
            t[i]=1;
            b++;
        }
    }
    if(b<m)
    {
        cout<<0;
        f=1;
    }
    long long sum;
    if(f==0)
    {
        sum=n*(n-1)/2;
        sum=sum%998244353;
        cout<<sum;
    }
    return 0;
}
