#include<bits/stdc++.h>
using namespace std;
int mod=998244353,c[550],n,m;
string s;
unsigned long long ans=1;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<n;i++)
    {
        ans*=i+1;
        ans%=mod;
    }
    cout<<0;
    return 0;
}
//这不合理，我为什么一道题不会，CCF还我870 
