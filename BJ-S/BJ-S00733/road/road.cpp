#include<bits/stdc++.h>
using namespace std;
namespace compile{
    void begin(){
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
        ios::sync_with_stdio(0);
        return ;
    }
    void end(){
        return ;
    }
}
#define ll long long
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k;
ll ans=0;
struct side{
    int u,v,w;
    bool operator<(const side &sd)const{
        return w>sd.w;
    }
}x[2*M];
bool cmp(side u,side v){
    return u.w<v.w;
}
int fa[N+K];
int getfa(int x){
    return x==fa[x] ? x : fa[x]=getfa(fa[x]);
}
int c[K];
int a[K][N];
void init(){
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        x[i]=(side){u,v,w};
    }
    sort(x+1,x+m+1,cmp);
    for(int j=1;j<=k;j++){
        cin>>c[j];
        for(int i=1;i<=n;i++){
            cin>>a[j][i];
        }
    }
    return ;
}
priority_queue<side> q;
void clear(){
    while(!q.empty())q.pop();
    for(int i=1;i<=n+K;i++){
        fa[i]=i;
    }
    return ;
}
void add(int id){
    for(int i=1;i<=n;i++){
        q.push((side){id+n,i,a[id][i]});
    }
    return ;
}
ll solve(int cnt){
    ll res=0;
    for(int i=1,fu,fv;i<=m;i++){
        while(!q.empty() and q.top().w<x[i].w){
            side d=q.top();q.pop();
            fu=getfa(d.u);fv=getfa(d.v);
            if(fu==fv)continue;
            //cerr<<d.u<<' '<<d.v<<' '<<d.w<<endl;
            fa[fv]=fu;
            res+=d.w;
            cnt--;
            if(!cnt)return res;
        }
        fu=getfa(x[i].u);fv=getfa(x[i].v);
        if(fu==fv)continue;
        fa[fv]=fu;
        res+=x[i].w;
        //cerr<<x[i].u<<' '<<x[i].v<<' '<<x[i].w<<endl;
        cnt--;
        if(!cnt)return res;
    }
    return res;
}
void work(){
    ans=LONG_LONG_MAX;
    int p=(1<<k);
    for(int i=0,cnt;i<p;i++){
        clear();
        cnt=n-1;
        ll sum=0;
        //cerr<<"case"<<i+1<<":";
        for(int j=0;j<k;j++){
            if((1<<j)&i){
                add(j+1);
                sum+=c[j+1];
                cnt++;
                //cerr<<j+1<<' ';
            }
        }
        //cerr<<endl;
        //cerr<<"side:"<<cnt<<endl;
        //cerr<<sum<<' ';
        if(sum>=ans)continue;
        sum+=solve(cnt);
        //cerr<<sum<<endl;
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return ;
}
signed main(){
    compile::begin();
    init();
    work();
    compile::end();
    return 0;
}