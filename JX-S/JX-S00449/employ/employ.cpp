#include<bits/stdc++.h>
#define ll long long
const ll maxn=1000050;
using namespace std;
ll n,m,x,mod=998244353;
char a[maxn];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]=='1')
        {
            x++;
        }
        x%=mod;
    }
    cout<<x%mod;
    return 0;
}
