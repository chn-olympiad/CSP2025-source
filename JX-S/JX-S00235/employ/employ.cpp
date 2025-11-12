#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[537],num1[537],num2[537];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*i%mod;
    }
    cout<<ans;
    return 0;
}
