#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

const int N=1e5+5;
int n,m;
string s;
int ans;

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    int a[n];
    getline(cin,s);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        ans=ans*(n+1-i);
    }
    ans=ans%998244353;
    cout<<ans;
    return 0;
}
