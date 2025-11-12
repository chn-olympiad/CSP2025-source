#include <bits/stdc++.h>
using namespace std;
int n,s[10005];
long long sum=0;
double ans=1;
const long long mod=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    if(n<3)
    cout<<0;
    if(n==3)
    {
        if((s[1]+s[2]>s[3] && s[2]+s[3]>s[1]) && s[1]+s[3]>s[2])
            cout<<1;
        else
            cout<<0;
    }
    else
    {
        for(int i=3;i<=n;i++)
        {
            ans=1;
            for(int j=n;j>=n-i+1;j--)
            {
                ans=(ans*j/(j-(n-i)));
            }
            sum=(sum+int(ans))%mod;
        }
        cout<<sum;
    }
    return 0;
}
