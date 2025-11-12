#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e6+10;
struct node{
    ll u,v,c;
};
ll n,m,k,b[20][N],fa[N],ans;
bool vis[N];
vector<node> a,op;
ll Find(ll x){return fa[x]==x?x:x=Find(fa[x]);}
bool cmp(node a,node b){
    return a.c<b.c;
}
ll Search(ll val){
    ll l=0,r=op.size()-1,mid,ans=-1;
    while(l<=r){
        mid=l+r>>1;
        if(op[mid].c>=val){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return (ans==-1?m+1:ans);
}
void change(ll p){
    for(ll i=1;i<=n;i++){
        op.insert(op.begin()+Search(b[p][i]),(node){n+p,i,b[p][i]});
    }
}
ll kruscal(vector<node> op){
    ll cost=0;
    memset(vis,0,sizeof(vis));
    for(node i:op){
        ll u=Find(i.u),v=Find(i.v);
        if(u!=v){
            cost+=i.c;
            fa[u]=v;
            if(i.u>n&&!vis[i.u-n]){
                cost+=b[i.u-n][n+1];
                vis[i.u-n]=1;
            }
        }
    }
    return cost;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1,u,v,c;i<=m;i++){
        cin>>u>>v>>c;
        a.push_back((node){u,v,c});
    }
    sort(a.begin(),a.end(),cmp);
    for(ll i=1;i<=k;i++){
        cin>>b[i][n+1];
        for(ll j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    for(ll i=1;i<=n;i++)fa[i]=i;
    ans=kruscal(a);
    for(ll i=1;i<=k;i++){
        for(ll j=1;j<=n;j++)fa[j]=j;
        op=a;
        change(i);
        ans=min(ans,kruscal(op));
    }
    for(ll j=1;j<=n;j++)fa[j]=j;
    op=a;
    for(ll i=1;i<=k;i++){
        change(i);
    }
    ans=min(ans,kruscal(op));
    cout<<ans;
    return 0;
}
