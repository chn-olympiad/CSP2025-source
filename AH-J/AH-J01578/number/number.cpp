#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

typedef long long ll;
typedef double db;

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string S;
    cin>>S;
    vector<int> cnt(12,0);
    for(auto i:S)
        if(i>='0'&&i<='9')
            cnt[i-'0']++;
    for(int i=9;i>=0;i--)
        rep(j,1,cnt[i])
            cout<<i;
    cout<<endl;
}

/*
# 上善若水，厚德载物——CSP 2025 游记

$1^{10}+...+100^{10}=959924142434241924250$

```py
ans=0
for i in range(1,101):
    ans+=i**10
print(ans)
```

T1 T2 easy，30 min。

T3 注意到性质，想到下面一个贪心：

```cpp
int l=1,ans=0;
while(l<=N)
{
    bool fyy=0;
    rep(r,l,N)
    {
        bool can=1;
        rep(k,0,22)
            if((S[k][r]-S[k][l-1])%2!=((K>>k)&1))
                can=0;
        if(can)
        {
            ans++,l=r+1,fyy=1;
            break;
        }
    }
    if(!fyy) l++;
}
cout<<ans<<endl;
```
委了，但是可以 dp

```cpp
vector<int> dp(N+1,0),f(N+1,0);
rep(i,1,N)
{
    rep(j,1,i)
    {
        bool can=1;
        rep(k,0,22)
            if((S[k][i]-S[k][j-1])%2!=((K>>k)&1))
                can=0;
        if(can)
            dp[i]=max(dp[i],f[j-1]+1);
    }
    f[i]=max(f[i-1],dp[i]);
}
int ans=0;
rep(i,1,N) ans=max(ans,dp[i]);
cout<<ans<<endl;
```

把转移提出来，但是要高速维护符合条件的 $j$，这点我就做不到了。

T4 暴力+性质。

分：100+100+60+(40+24)=324 会挂很多。

luogu: da_ke userid=766675

$\mathscr{A.F.O.}$
*/