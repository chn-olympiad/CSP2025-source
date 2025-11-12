#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
const int maxm=3e6+5;
vector<pair<int,ll> > t[maxn],g[maxn];
int n,m,k,cnt,vis[maxn],kk;
int s[maxn],h[maxn];
ll c[maxn],sz[maxn],ans,res;
struct node{
    ll u,v,num;int l;
    bool operator<(const node &a)const{
        return num>a.num;
    }
}b[maxm];
bool cmp(node a,node b){return a.num<b.num;}
priority_queue<node> q;
int Find(int x){
    if(s[x]==x) return x;
    return s[x]=Find(s[x]);
}
void prim(){
    for(auto i:t[1]){
        int v=i.first;
        ll w=i.second;
        q.push({1,v,w+c[v]});
    }
    while(q.size()){
        auto tmp=q.top();
        q.pop();
        int xx=Find(tmp.u),yy=Find(tmp.v);
        if(xx==yy) continue;
        s[xx]=yy;
        if(tmp.v>n&&tmp.l==1&&vis[tmp.v]) tmp.num-=c[tmp.v];
        g[tmp.u].push_back({tmp.v,tmp.num});
        g[tmp.v].push_back({tmp.u,tmp.num});
        ans+=tmp.num;
        for(auto i:t[tmp.v]){
            int v=i.first;
            ll w=i.second;
            int xx=Find(tmp.v),yy=Find(v);
            if(xx==yy) continue;
            if(v>n){
                if(vis[v]){
                    q.push({tmp.v,v,w});
                    vis[v]=1;
                }else q.push({tmp.v,v,w+c[v],1});
            }else q.push({tmp.v,v,w});
        }
    }
}
void kru(){
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int aa=Find(b[i].u),bb=Find(b[i].v);
		if(aa==bb) continue;
        g[b[i].u].push_back({b[i].v,b[i].num});
        g[b[i].v].push_back({b[i].u,b[i].num});
		ans+=b[i].num;
		s[aa]=bb;
	}
}
void dfs1(int x,int fa,ll tmp){
    sz[x]=tmp;
    for(auto i:g[x]){
        int v=i.first;
        ll w=i.second;
        if(v==fa) continue;
        dfs1(v,x,w);
        h[x]+=h[v];
        sz[x]+=sz[v]+w;
    }
}
void dfs2(int x,int fa){
    if(h[x]==0){
        res+=sz[x];
        return;
    }
    for(auto i:g[x]){
        int v=i.first;
        ll w=i.second;
        if(v==fa) continue;
        dfs2(v,x);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++) s[i]=i;
    for(int i=1;i<=n;i++) h[i]=1;
    for(int i=1;i<=m;i++){
        int u,v;ll w;
        cin>>u>>v>>w;
        t[u].push_back({v,w});
        t[v].push_back({u,w});
        b[++cnt]={u,v,w};
    }
    bool flag=0;
    for(int i=1;i<=k;i++){
        cin>>c[i+n];if(c[i+n]!=0){flag=1;} 
        for(int j=1;j<=n;j++){
            ll x;cin>>x;
            t[i+n].push_back({j,x});
            t[j].push_back({i+n,x});
			b[++cnt]={i+n,j,x};
		}
    }
    if(flag==0){
		kru();
    	dfs1(1,0,0);
    	dfs2(1,0);
		cout<<ans-res<<"\n";
		return 0;
	}
    prim();
	dfs1(1,0,0);dfs2(1,0);
    cout<<ans-res<<"\n";
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 0 0 0
0 0 0 0 0
*/