#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define int long long
using namespace std;

int t,n;
int num[100005][3];
int dp[205][105][105];
int dp2[2][50005];

void Solve1() {
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=min(i,n>>1);j++)
            for(int k=0;k<=min(i-j,n>>1);k++) {
                int t = i-j-k;
                if(t < 0) continue;
                if(t > (n>>1)) continue;
                if(j) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]+num[i][0]);
                if(k) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+num[i][1]);
                if(t) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]  +num[i][2]);
            }
    int ans = 0;
    for(int j=0;j<=(n>>1);j++)
        for(int k=0;k<=(n>>1);k++)
            ans = max(ans,dp[n][j][k]);
    printf("%lld\n",ans);
}

void SolveA() {
    vector<int> vec;
    for(int i=1;i<=n;i++)
        vec.emplace_back(num[i][0]);
    sort(vec.begin(),vec.end(),greater<int>());
    int ans = 0;
    for(int i=1;i<=(n>>1);i++)
        ans += vec[i-1];
    printf("%lld\n",ans);
}

void SolveB() {
    memset(dp2,0,sizeof dp2);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=min(i,n>>1);j++) {
            int tmp = i-j;
            if(tmp) dp2[i&1][j] = dp2[i-1&1][j]+num[i][1];
            if(j) dp2[i&1][j] = max(dp2[i&1][j],dp2[i-1&1][j-1]+num[i][0]);
        }
    printf("%lld\n",dp2[n&1][n>>1]);
}

bool Judge(int x[3]) {
    return (x[0]<=(n>>1) && x[1]<=(n>>1) && x[2]<=(n>>1));
}

void SolveC() {
    int ans = 0;
    int sumid[3] = {};
    for(int i=1;i<=n;i++) {
        int tmp = max({num[i][0],num[i][1],num[i][2]});
        ans += tmp;
        if(tmp == num[i][0]) sumid[0]++;
        else if(tmp == num[i][1]) sumid[1]++;
        else sumid[2]++;
    } if(Judge(sumid)) {
        printf("%lld\n",ans);
        return;
    } int idx = 0;
    for(int i=0;i<3;i++)
        if(sumid[i] > (n>>1)) {
            idx = i;
            break;
        }
    vector<int> vec;
    for(int i=1;i<=n;i++) {
        int tmp = max({num[i][0],num[i][1],num[i][2]});
        if(tmp == num[i][idx]) vec.push_back(i);
    } sort(vec.begin(),vec.end(),[&](int a,int b){ return num[a][idx]-max(num[a][(idx+1)%3],num[a][(idx+2)%3]) < num[b][idx]-max(num[b][(idx+1)%3],num[b][(idx+2)%3]); });
    int temp = sumid[idx], topp=0;
    while(temp > (n>>1)) {
        int top = vec[topp++]; temp--;
        ans -= num[top][idx]-max(num[top][(idx+1)%3],num[top][(idx+2)%3]);
    } printf("%lld\n",ans);
}

signed main() 
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    scanf("%lld",&t);
    while(t--) 
    {
        bool flagA = true;
        bool flagB = true;

        scanf("%lld",&n);
        for(int i=1;i<=n;i++) {
            scanf("%lld%lld%lld",num[i],num[i]+1,num[i]+2);
            if(num[i][1] || num[i][2]) flagA = false;
            if(num[i][2]) flagB = false;
        }
        if(n <= 200) Solve1();
        else if(flagA) SolveA();
        else if(flagB) SolveB();
        else SolveC();
    } return 0;
}