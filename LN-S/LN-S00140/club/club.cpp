#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+7;
bitset<N> pd;
bitset<4> pd2;
struct node{
    int id,val;
    bool operator <(const node &x)const{return val>x.val;}
};
priority_queue<node> q[4];
int cnt[4];
int ans;
bitset<N> pd1;
bitset<4> pd12;
struct node1{
    int id,val;
    bool operator <(const node1 &x)const{return val<x.val;}
};
priority_queue<node1> q1[4];
int cnt1[4];
int ans1;
void init(){
    pd.reset();pd2.reset();
    cnt[1]=cnt[2]=cnt[3]=0;
    ans=0;
    while(!q[1].empty()) q[1].pop();
    while(!q[2].empty()) q[2].pop();
    while(!q[3].empty()) q[3].pop();
    pd1.reset();pd12.reset();
    cnt1[1]=cnt1[2]=cnt1[3]=0;
    ans1=0;
    while(!q1[1].empty()) q1[1].pop();
    while(!q1[2].empty()) q1[2].pop();
    while(!q1[3].empty()) q1[3].pop();
}
void solve(){
    int n;cin>>n;
    if(n>30){
        init();
        for(int i=1;i<=n;i++){
            int a,b,c;cin>>a>>b>>c;
            q[1].push({i,a});q[2].push({i,b});q[3].push({i,c});
            q1[1].push({i,a});q1[2].push({i,b});q1[3].push({i,c});
        }
        for(int i=1;i<=n;i++){
            while(!q[1].empty()&&pd[q[1].top().id]) q[1].pop();
            while(!q[2].empty()&&pd[q[2].top().id]) q[2].pop();
            while(!q[3].empty()&&pd[q[3].top().id]) q[3].pop();
            int maxn=-1,maxid=0;
    //        equal?
            if(!pd2[1]){
                if(q[1].top().val>maxn||(q[1].top().val==maxn&&cnt[1]<cnt[maxid])) maxn=q[1].top().val,maxid=1;
            }
            if(!pd2[2]){
                if(q[2].top().val>maxn||(q[2].top().val==maxn&&cnt[2]<cnt[maxid])) maxn=q[2].top().val,maxid=2;
            }
            if(!pd2[3]){
                if(q[3].top().val>maxn||(q[3].top().val==maxn&&cnt[3]<cnt[maxid])) maxn=q[3].top().val,maxid=3;
            }
            ans+=maxn;cnt[maxid]++;pd[q[maxid].top().id]=1;q[maxid].pop();
            if(cnt[maxid]==(n>>1)) pd2[maxid]=1;
        }
        for(int i=1;i<=n;i++){
            while(!q1[1].empty()&&pd1[q1[1].top().id]) q1[1].pop();
            while(!q1[2].empty()&&pd1[q1[2].top().id]) q1[2].pop();
            while(!q1[3].empty()&&pd1[q1[3].top().id]) q1[3].pop();
            int maxn=-1,maxid=0;
    //        equal?
            if(!pd12[1]){
                if(q1[1].top().val>maxn||(q1[1].top().val==maxn&&cnt1[1]<cnt1[maxid])) maxn=q1[1].top().val,maxid=1;
            }
            if(!pd12[2]){
                if(q1[2].top().val>maxn||(q1[2].top().val==maxn&&cnt1[2]<cnt1[maxid])) maxn=q1[2].top().val,maxid=2;
            }
            if(!pd12[3]){
                if(q1[3].top().val>maxn||(q1[3].top().val==maxn&&cnt1[3]<cnt1[maxid])) maxn=q1[3].top().val,maxid=3;
            }
            ans1+=maxn;cnt1[maxid]++;pd1[q1[maxid].top().id]=1;q1[maxid].pop();
            if(cnt1[maxid]==(n>>1)) pd12[maxid]=1;
        }
        cout<<max(ans,ans1)<<'\n';return ;
    }else{
        int a[35],b[35],c[35];
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        int dp[35][20][20][20];
        memset(dp,0,sizeof(dp));
        int anshere=0;
        for(int x=1;x<=n;x++)
            for(int i=0;i<=(n>>1);i++)
                for(int j=0;j<=(n>>1);j++)
                    for(int k=0;k<=(n>>1);k++){
                        if(i) dp[x][i][j][k]=max(dp[x][i][j][k],dp[x-1][i-1][j][k]+a[x]);
                        if(j) dp[x][i][j][k]=max(dp[x][i][j][k],dp[x-1][i][j-1][k]+b[x]);
                        if(k) dp[x][i][j][k]=max(dp[x][i][j][k],dp[x-1][i][j][k-1]+c[x]);
                        anshere=max(dp[x][i][j][k],anshere);
                    }
        cout<<anshere<<'\n';return ;
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--) solve();
    return 0;
}
