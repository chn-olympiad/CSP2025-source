#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1145;
int n,p=998244353;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;int ans=1;
    for(int i=1;i<=n;i++)ans=ans*i%p;cout<<ans;
    return 0;
}
