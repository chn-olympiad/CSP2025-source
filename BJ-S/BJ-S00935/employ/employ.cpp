#include <bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
#define endl "\n"
#define print(x) cerr<<#x<<"="<<x<<"\n"
#define dbg() cerr<<"LINE "<<__LINE__<<"\n"
using namespace std;
int n,m,a[555],b[555],dp[(1<<18)+5][22];//dp[i][j]人的使用情况为i，其中通过了j个人，达到当前状态的总方案数
int popcnt(int x){
    int ret=0;
    for(int i=0;i<22;i++){
        ret+=(x>>i)&1;
    }
    return ret;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    string aaa;
    cin>>aaa;
    for(int i=1;i<=n;i++){
        a[i]=aaa[i-1]-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    dp[0][0]=1;
    for(int i=0;i<(1<<n)-1;i++){
        for(int j=0;j<=popcnt(i);j++){
            for(int k=1;k<=n;k++){
                if(1&(i>>(k-1)))continue;
                int tmp,t=popcnt(i)+1;
                if(a[t]==0||t-1-j>=b[k])tmp=0;
                else tmp=1;
                dp[i^(1<<(k-1))][j+tmp]+=dp[i][j];
            }
        }
    }
    int ans=0;
    for(int i=m;i<=n;i++){
        ans+=dp[(1<<n)-1][i];
    }
    cout<<ans;
    return 0;
}
