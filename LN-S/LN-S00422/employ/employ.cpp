#include<bits/stdc++.h>
using namespace std;
int n,m,a[509];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
        ans%=998244353;
    }
    cout<<ans;
}
