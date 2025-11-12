#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long jc(int x)
{
    long long ans=1;
    for(int i=1;i<=x;i++)
    {
        ans=(ans%mod*i%mod)%mod;
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    cout<<jc(n);
    return 0;
}
