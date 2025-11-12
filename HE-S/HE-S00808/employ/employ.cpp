#include<bits/stdc++.h>
using namespace std;
int c[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string a;
    cin>>a;
    int tg=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]!='1')
        {
            tg=0;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    int ans=0;
    // if(tg==1)
    {
        for(int i=2;i<=n;i++)
        {
            ans=(ans*i)%998244353;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
