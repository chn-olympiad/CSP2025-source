#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct edge{int u, v, wt;}ed[1000005], the[100005], In[11][10005];
int n, m, k, c[15], a[15][10005], fa[11005], len, le, noww[15], hel[15];
ll ans=LLONG_MAX;
bool cmp(edge a, edge b){return a.wt<b.wt;}
int getfa(int u){return fa[u]=((fa[u]==u)?u:getfa(fa[u]));}
inline void init(){
    for(int i=1; i<=n; i++)fa[i]=i;
    for(int i=1; i<=m; i++){
        int uu=getfa(ed[i].u), vv=getfa(ed[i].v);
        if(uu==vv)continue;
        fa[uu]=vv;In[k][++len]=ed[i];
    }
}
inline ll solve(){
    ll tot=0;
    for(int i=1; i<=n+10; i++)fa[i]=i;
    for(int i=1; i<=le; i++){
        int uu=getfa(the[i].u), vv=getfa(the[i].v);
        if(uu==vv)continue;
        fa[uu]=vv;tot+=the[i].wt;
    }return tot;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        ed[i]={u, v, wt};
    }sort(ed+1, ed+1+m, cmp);
    for(int i=0; i<k; i++){
        cin >> c[i];
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            In[i][j]={n+i+1, j, a[i][j]};
        }
        sort(In[i]+1, In[i]+1+n, cmp);
        In[i][n+1].wt=INT_MAX;
    }
    init();In[k][n].wt=INT_MAX;
    for(int i=0; i<=k; i++)hel[i]=1;
    for(int S=0; S<(1<<k); S++){
        ll ad=0;le=0;int lenn=0, al=0, tot=0;
        for(int i=0; i<k; i++)if(S&(1<<i)){
            ad+=c[i];noww[++lenn]=i;al+=n;
        }noww[++lenn]=k;al+=n-1;
        while(tot<al){
            tot++;int minn=INT_MAX, p=0;
            for(int i=1; i<=lenn; i++)if(minn>In[noww[i]][hel[noww[i]]].wt){
                minn=In[noww[i]][hel[noww[i]]].wt;p=noww[i];
            }the[++le]=In[p][hel[p]];
            hel[p]++;
        }
        ans=min(ans, solve()+ad);
        for(int i=0; i<=k; i++)hel[i]=1;
    }cout << ans;
    return 0;
}