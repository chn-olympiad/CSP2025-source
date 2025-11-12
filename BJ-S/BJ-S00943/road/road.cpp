#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e6+50;
int n,m,k;
int u[MAXN],v[MAXN],w[MAXN];
struct Edge{
    int val;
    int e,s;
    bool operator<(const Edge a)const {
        return val>a.val;
    }
};
priority_queue<Edge>eg;
int c[MAXN],a[15][MAXN];
int fa[MAXN];
int findfa(int x){
    if(fa[x]==x)return x;
    else return fa[x]=findfa(fa[x]);
}
int solve(priority_queue<Edge>eg,int chos){
    for(int i=1;i<=n+k;i++)fa[i]=i;
    int res=0,cot=0;
    for(int i=1;i<=k;i++){
        if((1<<i-1)&chos){
            res+=c[i];
            for(int j=1;j<=n;j++)eg.push({a[i][j],j,i+n});
            cot++;
        }
    }
    int cnt=0;
    while(!eg.empty()&&cnt<n+cot-1){
        auto [val,e,s]=eg.top();
        //cout<<e<<" "<<s<<" ";
        eg.pop();
        e=findfa(e);
        s=findfa(s);
        if(s==e)continue;
        fa[s]=e;
        res+=val;
        cnt++;
        //cout<<res<<'\n';
    }
    //cout<<res<<'\n';
    return res;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        eg.push({w[i],v[i],u[i]});
    }
    int sum=0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
        sum+=c[i];
    }
    int ans=2e18;
    if(sum==0){
        cout<<solve(eg,(1<<k)-1);
        return 0;
    }
    for(int i=0;i<=(1<<k)-1;i++){
        //cout<<i<<'\n';
        ans=min(solve(eg,i),ans);
        //cout<<ans<<'\n';
    }
    cout<<ans;
    return 0;
}

