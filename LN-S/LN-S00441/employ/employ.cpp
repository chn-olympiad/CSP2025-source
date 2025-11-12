#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int ans=1,num=0,n,m;cin>>n>>m;
    string s;cin>>s;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(x!=0)    num++;
    }
    if(num<m)   cout<<0;
    else
    {
        for(int i=1;i<=m;i++)
        {
            ans*=(n-i+1);
            ans%=mod;
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
}
