#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back
#define pii pair<int,int>
#define piii pair<int,pii >
#define fi first
#define se second
#define mid (l+r)/2
const int N=1e4+20,M=1e6+5;
int n,m,k,Fa[N],a[11][N],cost[11];
ll ans;
piii edge[M],edge2[N],edgenow[11*N];
int Find(const int x){
    if(Fa[x]==x)return x;
    return Fa[x]=Find(Fa[x]);
}
int tot,s1,s2;
void dfs(const int cnt,bool c[],ll sum){
    if(sum>=ans)return;
    if(cnt==k+1){
        tot=n-1;
        for(int i=1;i<=k;i++){
            if(c[i]==0)continue;
            for(int j=1;j<=n;j++){
                edgenow[++tot]={a[i][j],{i+n,j}};
            }
        }
        if(tot==n-1)return;
        for(int i=1;i<=n+k;i++){
            Fa[i]=i;
        }
        stable_sort(edgenow+1,edgenow+tot+1);
        for(int i=1;i<=tot;i++){
            if(Find(edgenow[i].se.fi)==Find(edgenow[i].se.se))continue;
            sum+=edgenow[i].fi;
            if(sum>=ans)return;
            Fa[Find(edgenow[i].se.fi)]=Find(edgenow[i].se.se);
        }
        ans=min(ans,sum);
        for(int i=1;i<n;i++)edgenow[i]=edge2[i];
        return;
    }
    dfs(cnt+1,c,sum);
    c[cnt]=1;
    dfs(cnt+1,c,sum+cost[cnt]);
    c[cnt]=0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>edge[i].se.fi>>edge[i].se.se>>edge[i].fi;
    }
    for(int i=1;i<=k;i++){
        cin>>cost[i];
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    sort(edge+1,edge+m+1);
    for(int i=1;i<=n;i++){
        Fa[i]=i;
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(Find(edge[i].se.fi)==Find(edge[i].se.se))continue;
        cnt++;
        ans+=edge[i].fi;
        Fa[Find(edge[i].se.fi)]=Find(edge[i].se.se);
        edgenow[cnt]=edge2[cnt]=edge[i];
    }
    bool c[11]={0};
    dfs(1,c,0);
    cout<<ans;
    return 0;
}