#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n,m;cin>>n>>m;
    string s;cin>>s;
    for(int i=0;i<n;i++)
    {
        int c;cin>>c;
    }
    int ans=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')ans=(ans+1)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}

