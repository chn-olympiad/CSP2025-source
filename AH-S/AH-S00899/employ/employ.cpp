#include<bits/stdc++.h>
using namespace std;
int n,m;
long long cnt=1,sum=1;
const int mod=998244353;
string s;
int c[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    for(int j=m;j<=n;j++)
    {
        sum=1;
        for(int i=n;i>j;i--)
        {
            sum=(sum%mod*i)%mod;
        }
        cnt=cnt%mod*sum%mod;
        cnt%=mod;
    }
    printf("%lld",cnt);
    return 0;
}
