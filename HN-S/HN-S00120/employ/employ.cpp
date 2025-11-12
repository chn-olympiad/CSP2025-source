#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr first
#define sc second
#define pii pair<int,int>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define ro(i,r,l) for(inr i=r;i>=l;i--)
const int N=505,M=998244353;
int n,m,c[N];
string a;
namespace bf{
    int dp[2][21][(1ll<<18)+5],tmp[21];
    void solve(){
        dp[0][0][0]=1;
        fo(i,1,n){
            fo(s,0,(1ll<<n)-1){
                int cnt=0;
                fo(j,1,n)
                    if ((s>>(j-1))&1)
                        cnt++;
                if (cnt!=i)
                    continue;
                fo(j,0,i)
                    dp[i&1][j][s]=0;
            }
            fo(s,0,(1ll<<n)-1){
                int cnt=0;
                fo(j,1,n)
                    if ((s>>(j-1))&1)
                        cnt++,tmp[j]=1;
                if (cnt!=i)
                    continue;
                fo(t,1,n){
                    if (!tmp[t])
                        continue;
                    fo(j,0,i){
                        if (j&&(a[i]=='0'||c[t]<=j-1))
                            (dp[i&1][j][s]+=dp[i&1^1][j-1][s^(1ll<<(t-1))])%=M;
                        if (a[i]=='1'&&c[t]>j)
                            (dp[i&1][j][s]+=dp[i&1^1][j][s^(1ll<<(t-1))])%=M;
                    }
                }
            }
        }
        int rs=0;
        fo(j,0,n-m)
            (rs+=dp[n&1][j][(1ll<<n)-1])%=M;
        cout<<rs<<'\n';
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>a;
    a=' '+a;
    fo(i,1,n)
        cin>>c[i];
    if (n<=18){
        bf::solve();
        return 0;
    }
    cout<<"0\n";
    return 0;
}
/*
我常常追忆过去。

生命瞬间定格在脑海……

我该在哪里停留？我问我自己。
*/