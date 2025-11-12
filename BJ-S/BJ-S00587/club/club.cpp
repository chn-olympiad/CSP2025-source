#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N=1e5+10,M=210;

int n;
int a[N][3];
int dp[M][M][M];
// 在前i个人中，有j个人选1，k个人选2时的最大价值

void work1() { //n<=200
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n/2;j++) {
            for(int k=0;k<=n/2;k++) {
                int l=i-j-k;
                if(l>n/2) continue;
                if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
                if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
                if(l>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
            }
        }
    }
    int maxn=0,x,y,z;
    for(int i=0;i<=n/2;i++) {
        for(int j=0;j<=n/2;j++) {
            int l=n-i-j;
            if(l>n/2) continue;
            maxn=max(maxn,dp[n][i][j]);
        }
    }
    cout<<maxn<<"\n";
}

void work2() { //A
    vector<int> d;
    for(int i=1;i<=n;i++) d.push_back(a[i][1]);
    sort(d.begin(),d.end());
    int ans=0;
    for(int i=1;i<=n/2;i++) ans+=d[i];
    cout<<ans<<"\n";
}

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--) {
        cin>>n;
        bool flag1=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0) flag1=1;
        }
        if(n<=200) work1();
        else if(flag1==0) work2();
        else cout<<"\n";
    }
}