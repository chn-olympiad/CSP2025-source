#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+5;
int n,m,k,c[N],a[22][N],fa[M],ans=1e18,flag1;
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
struct Edge{
    int u,v,w,id;
}edge[M*2];
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
int solve(int sta){
    int cnt=0,res=0,tot=0;
    for(int i=1;i<=k;++i){
        if(sta>>(i-1)&1)
            res+=c[i],tot++;
    }
    for(int i=1;i<=n+k;++i){
        fa[i]=i;
    }
    for(int i=1;i<=m;++i){
        int u=edge[i].u,v=edge[i].v,w=edge[i].w,id=edge[i].id;
        if((id && ((sta>>(id-1)&1) == 0)) )continue;
        if(find(u)==find(v))continue;
        fa[find(u)]=find(v);
        res+=w;
        // cout<<w<<' '<<u<<' '<<v<<'\n';
        cnt++;
        if(cnt>=n+tot-1){
            return res;
        }
    }
    return res;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
        edge[i].id=0;
    }
    for(int i=1;i<=k;++i){
        cin>>c[i];
        if(c[i])flag1=1;
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
            m++;
            edge[m].u=n+i;
            edge[m].v=j;
            edge[m].w=a[i][j];
            edge[m].id=i;
        }
    }
    sort(edge+1,edge+m+1,cmp);
    if(!flag1){//substack_A
        cout<<solve((1<<k)-1)<<'\n';
        return 0;
    }
    for(int sta=0;sta<(1<<k);++sta){
        // cout<<solve(sta)<<'\n';
        // for(int i=1;i<=n;++i){
        //     cout<<fa[i]<<' ';
        // }cout<<endl;
        ans=min(ans,solve(sta));
    }
    cout<<ans<<'\n';
    return 0;
}
// g++ /home/noi/Desktop/TTY/road.cpp -o road -std=c++14 -static
/*
record:
00:50   I think I know how to solve.
    It is that O(2^n) for choosing k,
    then using min_born_tree with m which added the chosen k, and it needs O(n). (How bad my English is!)

01:10   Oh no!! It is wrong, because of O(2^k*m) == O(1e9)

02:00   I can ac it V-V...

03:03   K! the title is vary unclear!

03:06   overcome example.
    hope 64

May do it on tree
*/