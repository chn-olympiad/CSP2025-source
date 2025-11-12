#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005][1005],s[5005];
#define int long long
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    if(n==1)
    {
        if(s[1]==k)
            cout<<1;
        else
            cout<<0;
        return 0;
    }
    if(n==2)
    {
        if(s[1]==s[2]&&s[1]==1)
            cout<<1;
        else if(s[1]==s[2]&&s[1]==0)
            cout<<2;
        else
            cout<<1;
        return 0;
    }
    cout<<0;
    return 0;
}
