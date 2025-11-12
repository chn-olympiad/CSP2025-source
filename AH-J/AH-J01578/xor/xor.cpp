#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define fdn(i,r,l) for(int i=r;i>=l;i--)

typedef long long ll;
typedef double db;

using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int N,K;
    cin>>N>>K;
    vector<int> A(N+1,0);
    rep(i,1,N)
        cin>>A[i];
    vector<vector<int>> B(33,vector<int>(N+1,0));
    rep(i,1,N)
        rep(j,0,22)
            B[j][i]=((A[i]>>j)&1);
    // 奇数个 1 是 1，偶数个 1 是 0
    vector<vector<int>> S;
    S=B;
    rep(i,0,22)
        rep(j,1,N)
            S[i][j]+=S[i][j-1];
    vector<int> dp(N+1,0),f(N+1,0),g(N+1,0);
    rep(i,1,N)
    {
        fdn(j,i,1)
        {
            bool can=1;
            rep(k,0,22)
                if((S[k][i]-S[k][j-1])%2!=((K>>k)&1))
                    can=0;
            if(can)
            {
                g[i]=j;
                break;
            }
        }
    }

    rep(i,1,N)
    {
        if(g[i]) dp[i]=max(dp[i],f[g[i]-1]+1);
        f[i]=max(f[i-1],dp[i]);
    }
    int ans=0;
    rep(i,1,N) ans=max(ans,dp[i]);
    cout<<ans<<endl;
}