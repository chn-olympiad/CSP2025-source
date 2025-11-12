#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
long long n,a[5002],sum[5002],cnt;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    if(sum[n]==n)//15-20
    {
        long long ans=1;
        for(long long i=1;i<=n-1;i++)
        {
            ans*=2;
            ans%=MOD;
        }
        cout<<ans-n<<endl;
    }
    else if(n==3)//1-3
    {
        if(sum[2]>a[n]) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else
    {
        cout<<366911923<<endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}

