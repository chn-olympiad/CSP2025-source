#include<bits/stdc++.h>
using namespace std;
namespace compile{
    void begin(){
        freopen("club.in","r",stdin);
        freopen("club.out","w",stdout);
        ios::sync_with_stdio(0);
        return ;
    }
    void end(){
        return ;
    }
}
#define int long long
const int N=1e5+5,M=205;
int n,h,ans;
int a[N][4];
int dp[M][M][M];
bool vis[N];
vector<int> x[4],v;
struct node{
    int id,val,type;
    bool operator<(const node &nd)const{
        return val<nd.val;
    }
};
priority_queue<node> q;
void init(){
    memset(a,0,sizeof(a));
    cin>>n;h=n/2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    return ;
}
int s(int i,int id){
    if(id==1){
        return min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
    }
    if(id==2){
        return min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
    }
    if(id==3){
        return min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
    }
    return 0;
}
void work(){
    if(n<=200){
        ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(j>h)break;
                for(int k=0;k<=i-j;k++){
                    if(k>h)break;
                    int p=i-j-k;
                    if(p>h)continue;
                    dp[i][j][k]=0;
                    if(j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
                    if(k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
                    if(p)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
                    //cerr<<i<<' '<<j<<' '<<k<<':'<<dp[i][j][k]<<endl;
                    ans=max(ans,dp[i][j][k]);
                }
            }
        }
        cout<<ans<<endl;
    }else{
        ans=0;
        memset(vis,0,sizeof(vis));
        x[1].clear();
        x[2].clear();
        x[3].clear();
        while(!q.empty())q.pop();
        v.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                q.push((node){i,a[i][j],j});
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            while(vis[q.top().id])q.pop();
            vis[q.top().id]=1;
            ans+=q.top().val;
            x[q.top().type].push_back(q.top().id);
        }
        int b=0;
        if(x[1].size()>h)b=1;
        if(x[2].size()>h)b=2;
        if(x[3].size()>h)b=3;
        if(b){
            for(auto i:x[b]){
                v.push_back(s(i,b));
            }
            sort(v.begin(),v.end());
            int cnt=x[b].size();
            for(int i=0;h+i<cnt;i++){
                ans-=v[i];
            }
        }
        cout<<ans<<endl;
    }
    return ;
}
signed main(){
    compile::begin();
    int t;
    cin>>t;
    while(t--){
        init();
        work();
    }
    compile::end();
    return 0;
}