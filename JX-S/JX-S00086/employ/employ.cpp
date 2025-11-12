#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10,mod=998244353;

int inv[N];
int fact[N],ifact[N];

void init()
{
    inv[1]=1;
    fact[0]=ifact[0]=1;
    for(int i=1; i<N; i++)
    {
        if(i!=1) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        fact[i]=fact[i-1]*i%mod;
        ifact[i]=ifact[i-1]*inv[i]%mod;
    }
}

int A(int a,int b)
{
    return fact[a]*ifact[a-b]%mod;
}

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    init();

    int n,m;
    cin>>n>>m;
    cout<<A(n,m);

    return 0;
}