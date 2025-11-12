#include<bits/stdc++.h>
using namespace std;
struct bian{
    int u, v, w;
};
bian e[2000010];
int n, m, k;
int c[11], a[11][10010];
int fa[10050];
bool cmp1(bian ljt, bian zrx){
    return ljt.w<zrx.w;
}
int findfa(int x){
    if(fa[x]!=x){
        fa[x]=findfa(fa[x]);
    }
    return fa[x];
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    int ts=0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(!c[i]) ts++;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(!a[i][j]) ts++;
        }
    }
    if(ts==k*(n+1)){
        cout<<0;
        return 0;
    }
    long long ans=1000000000000000;
    for(int xx=0;xx<(1<<k);xx++){
        long long sum=0;
        for(int i=0;i<=n+k;i++) fa[i]=i;
        int ava[11], sz=0;
        for(int i=0;i<k;i++){
            if(xx&(1<<i)){
                sz++;
                ava[sz]=i+1;//*
                sum+=c[i+1];
            }
        }
        int mm=m;
        for(int i=1;i<=sz;i++){
            for(int j=1;j<=n;j++){
                mm++;
                e[mm].u=ava[i]+n;
                e[mm].v=j;
                e[mm].w=a[ava[i]][j];
            }
        }
        sort(e+1, e+mm+1, cmp1);
        int nfa=n+sz, tg=1;
        while(nfa>1){
            while(findfa(e[tg].u)==findfa(e[tg].v)){
                tg++;
            }
            fa[fa[e[tg].u]]=fa[e[tg].v];
            sum+=e[tg].w;
            nfa--;
        }
        ans=min(ans, sum);
    }
    cout<<ans;
    return 0;
}