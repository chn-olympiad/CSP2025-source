#include<bits/stdc++.h>
#define K 11
#define N 10004
#define M 1000006
using namespace std;
int n,m,k;
pair<int,pair<pair<int,int>,int>>e[M];
int c[K];
int a[K][N];
int fa[N+K];
int siz[N+K];
int getfa(int p){
    if(fa[p]!=p)fa[p]=getfa(fa[p]);
    return fa[p];
}
inline bool merge(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x==y)return false;
    if(siz[y]<siz[x])swap(x,y);
    fa[x]=y;
    siz[y]+=siz[x];
    return true;
}
pair<int,pair<pair<int,int>,int>>g[N+N*K];
int cnt;
inline long long solve(int s){
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
        siz[i]=1;
    }
    long long res=0;
    for(int i=1;i<=k;i++){
        if((s>>(i-1))&1)res+=c[i];
    }
    for(int i=1;i<=cnt;i++){
        if((g[i].second.second==0)||((s>>(g[i].second.second-1))&1)){
            if(merge(g[i].second.first.first,g[i].second.first.second)){
                res+=g[i].first;
            }
        }
    }
    return res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].second.first.first>>e[i].second.first.second>>e[i].first;
        e[i].second.second=0;
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++){
        // cerr<<e[i].first<<" "<<e[i].second.first.first<<" "<<e[i].second.first.second<<endl;
        if(merge(e[i].second.first.first,e[i].second.first.second)){
            // cerr<<"ok\n";
            g[++cnt]=e[i];
        }
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            g[++cnt]=make_pair(a[i][j],make_pair(make_pair(n+i,j),i));
        }
    }
    sort(g+1,g+cnt+1);
    long long res=0x3f3f3f3f3f3f3f3fll;
    for(int s=0;s<(1<<k);s++){
        long long tmp=solve(s);
        // cerr<<s<<" "<<tmp<<endl;
        res=min(res,tmp);
    }
    cout<<res<<"\n";
}
