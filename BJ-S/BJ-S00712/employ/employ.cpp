#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=998244353,K=20;
int n,m,ans;
char ps[N];
int c[N],w;
int dp[1<<K][K];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ps[i];
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    dp[0][0]=1;
    for(int i=0;i<(1<<n);i++){
        int sl=1;
        for(int j=1;j<=n;j++){
            sl+=(i>>(j-1))&1;
        }
        for(int k=0;k<=n;k++){
            for(int j=1;j<=n;j++){
                if((i>>(j-1))&1)continue;
                dp[i|(1<<(j-1))][k+(ps[sl]=='0'||k>=c[j])]+=dp[i][k];
            }
        }
    }
    for(int i=0;i<=n-m;i++){
        ans+=dp[(1<<n)-1][i];
    }
    cout<<ans;
    return 0;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

3 2
101
1 1 2

*/
