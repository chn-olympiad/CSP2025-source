#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans=1;
int n,m,c[505],cnt;
string s;
long long qpl(int n)
{
    for(int i=n;i>=1;i--)
    {
        ans*=i;
        if(ans>=mod)ans%=mod;
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cnt=n;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==0)cnt--;
    }
    cout<<qpl(cnt)%mod<<endl;
    return 0;
}
