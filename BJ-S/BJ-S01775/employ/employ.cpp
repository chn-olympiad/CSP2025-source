#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD=998244353;
int n,m;
string s;
int a[505];

int jie(int x)
{
    int cul=1;
    for (int i=1; i<=x; i++)
    {
        cul*=i;
    }
    return cul;
}

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for (int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    int mx=jie(n);
    int ans=0;
    for (int _=1; _<=mx; _++)
    {
        int lq=0,sb=0;
        for (int i=1; i<=n; i++)
        {
            if (sb>=a[i]||s[i]=='0') sb++;
            else lq++;
            if (lq>=m) break;
        }
        if (lq>=m) ans++;
        ans%=MOD;
        next_permutation(a+1,a+n+1);
    }
    cout<<ans<<endl;
    return 0;
}