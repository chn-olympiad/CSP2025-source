#include<bits/stdc++.h>
using namespace std;
int t,n;
#define N 100005
int a[N][4];
int f[N][4];
int bl[N];
//int dp[105][105][105];
struct node{
    int val;
    int u,to;
}mn[N];
bool cmp(node a,node b){
    return a.val<b.val;
}
int tot;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        // if(n<=200){
        //     int ans=0;
        //     for(int x=1;x<=n;x++){
        //         for(int i=0;i<=n/2;i++){
        //             for(int j=0;j<=n/2;j++){
        //                 for(int k=0;k<=n/2;k++){
        //                     dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[x][1]);
        //                     dp[i][j+1][k]=max(dp[i+1][j][k],dp[i][j][k]+a[x][2]);
        //                     dp[i][j][k+1]=max(dp[i+1][j][k],dp[i][j][k]+a[x][3]);
        //                     ans=max({ans,dp[i+1][j][k],dp[i][j+1][k],dp[i][j][k+1]});
        //                 }
        //             }
        //         }
        //     }
        //     cout<<ans<<'\n';
        // }else
        // {
        int cnt[4]={0,0,0,0},ans=0;
        for(int i=1;i<=n;i++){
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])ans+=a[i][1],cnt[1]++,bl[i]=1;
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])ans+=a[i][2],cnt[2]++,bl[i]=2;
            else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])ans+=a[i][3],cnt[3]++,bl[i]=3;
        }
        int times=0;
        while(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
            // if(++times<=5)cout<<"now:"<<n<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
            for(int now=1;now<=3;now++){
                tot=0;
                if(cnt[now]<=n/2)continue;
                int x=now,y=x%3+1,z=y%3+1;
                for(int j=1;j<=n;j++){
                    if(bl[j]!=x)continue;
                    if(a[j][y]>a[j][z]){
                        mn[++tot].val=a[j][x]-a[j][y];
                        mn[tot].to=y;
                        mn[tot].u=j;
                    }else{
                        mn[++tot].val=a[j][x]-a[j][z];
                        mn[tot].to=z;
                        mn[tot].u=j;
                    }
                }
                sort(mn+1,mn+tot+1,cmp);
                for(int i=1;i<=cnt[x]-n/2;i++){
                    ans-=mn[i].val;
                    // cout<<a[mn[i].u][bl[mn[i].u]]<<" "<<a[mn[i].u][mn[i].to]<<'\n';
                    // cout<<x<<" "<<mn[i].to<<endl;
                    bl[mn[i].u]=mn[i].to;
                    cnt[mn[i].to]++;
                }
                cnt[x]=n/2;
            }
        }
        cout<<ans<<'\n';
        // for(int i=1;i<=n;i++){
        //     cout<<a[i][bl[i]]<<'\n';
        // }
        // }
    }
    return 0;
}
/*

10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926


3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0



*/
