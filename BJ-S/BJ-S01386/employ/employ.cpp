//第一次CSP-S考试 RP++
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=505;
const ll mod=998244353;

int n,m;
ll a[maxn];
string s;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>s;

    for(int i=1;i<=n;i++) cin>>a[i];

    ll ans=1;
    for(int i=1;i<=n;i++) ans=ans*i%mod;
    cout<<ans<<"\n";

    return 0;
}
