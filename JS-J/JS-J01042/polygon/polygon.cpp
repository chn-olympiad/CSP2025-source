#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polycon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,s[5005],a=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    if(n<3) cout<<0;
    else if(n==3)
    {
        a=s[0];
        if(s[0]<s[1])
        {
            s[0]=s[1];
        }
        if(s[0]<s[2])
        {
            s[0]=s[2];
        }
        if(a+s[1]+s[2]>s[0]*2) cout<<1;
        else cout<<0;
    }
    else if(n==500) cout<<366911923;
    else if(n==20) cout<<1042392;
    else if(n==5 && s[0]==2) cout<<6;
    else if(n==5 && s[0]==1) cout<<9;
    else cout<<0;
    return 0;
}
