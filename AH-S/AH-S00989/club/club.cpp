#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n, T;
const int N=1e5+5;
long long ans;
int dp[205][105][105];
int cb[N][4];
bool cmp(node x, node y) {
    return x.a>y.a;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>T;
    while(T--) {
        cin>>n; bool flag=0, flag2=0;
        memset(cb, 0, sizeof(cb));
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++) {
            scanf("%d%d%d", &cb[i][1],  &cb[i][2], &cb[i][3]);
            if(cb[i].b!=0&&cb[i].c!=0) flag=1;
            if(cb[i].c!=0) flag2=1;
        }
        if(n==2) {
            for(int i=1; i<=3; i++)
                for(int j=1; j<=3; j++) {
                    if(j==i) continue;
                    ans=max(ans, cb[1][i]+cb[2][j]);
                }
            cout<<ans<<endl; ans=0;
        } else if(flag==0) {
            sort(cb+1, cb+n+1, cmp);
            for(int i=1; i<=n/2; i++) ans+=cb[i].a;
            cout<<ans<<endl; ans=0;
        } else if(flag2==0) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n/2; j++)
                    for(int k=1; k<=n/2; k++) {
                         dp[i][j][k]=max(dp[i-1][j-1][k]+cb[i][1], dp[i-1][j][k-1]+cb[i][2]);
                    }
            }
            cout<<dp[n][n/2][n/2]<<endl;
        } else {
            for(int i=1; i<=n; i++) {
                ans+=max(cb[i][1], max(cb[i][2], cb[i][3]));
            }
            cout<<ans<<endl; ans=0;
        }
    }
    return 0;
} //#Shang4Shan3Ruo6Shui4
