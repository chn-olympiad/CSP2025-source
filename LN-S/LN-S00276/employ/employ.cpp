#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[1009];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    unsigned long long ans=1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        ans*=i;
        ans%=mod;
    }
    cout<<ans;
}
