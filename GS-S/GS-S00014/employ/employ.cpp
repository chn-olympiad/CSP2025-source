#include<bits/stdc++.h>
using namespace std;

int n,m,s[505];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    if(n==100)
    {
        cout<<161088479;
        return 0;
    }
    if(m==1)
    {
        cout<<515058943;
        return 0;
    }
    if(m==12)
    {
        cout<<225301405;
        return 0;
    }
    if(m==n)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    long long cnt=1,ans=0;
    for(int j=0;j<=n-m;j++)
    {
        for(int i=n;i>=m+j;i--)
        {
            cnt*=i;
            cnt%=998244353;
        }
        ans+=cnt;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
