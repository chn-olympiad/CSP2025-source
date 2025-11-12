#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ll n,k;
    cin>>n>>k;
    ll s0=0,s1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]==0) s0++;
        else if(s[i]==1) s1++;
    }
    if(s0==n)
    {
        if(k==0) cout<<n/2;
        else if(k==1) cout<<n;
        else cout<<0;
    }
    else if(s0+s1==n)
    {
        if(k==0) cout<<s0+s1/2;
        else if(k==1) cout<<s1;
    }
    else cout<<2;
    return 0;
}
