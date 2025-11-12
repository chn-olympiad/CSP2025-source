#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005][3];
int dp[205][205];
bool vis[100005];
struct st{
    int v,x,y;
    bool operator<(const st& other) const{
        return v>other.v;
    }
};
void fun(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
    if(n<=0){
        memset(dp,0,sizeof(dp));
        int maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=n/2;j>=0;j--){
                for(int k=n/2;k>=0;k--){
                    if(i-j-k>n/2) continue;
                    dp[j][k]=max({
                        (j?(dp[j-1][k]+a[i][0]):0),
                        (k?(dp[j][k-1]+a[i][1]):0),
                        ((i-j-k)?(dp[j][k]+a[i][2]):0)
                    });
                    if(i==n) maxn=max(maxn,dp[j][k]);
                }
            }
        }
        cout<<maxn<<endl;
        return ;
    }
    memset(vis,0,sizeof(vis));
    vector<st> q;
    for(int i=1;i<=n;i++){
        q.push_back({a[i][0],i,0});
        q.push_back({a[i][1],i,1});
        q.push_back({a[i][2],i,2});
    }
    sort(q.begin(),q.end());
    int ans=0,cnt[3]={0};
    for(st i:q){
        if(vis[i.x]) continue;
        if(cnt[i.y]>=n/2) continue;
        cnt[i.y]++;
        vis[i.x]=1;
        ans+=i.v;
    }
    cout<<ans<<endl;
    return ;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) fun();
    return 0;
}