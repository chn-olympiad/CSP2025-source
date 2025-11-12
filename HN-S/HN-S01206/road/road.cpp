#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+15,M=1e6+15;
int n,m,k,ans,u[M],v[M],w[M],fa[N],r[M],a[11][N],c[11],tot,sum[N];
vector<int> x[N],y[N],z[N],f[N];
bool cmp(int a,int b){
    return w[a]<w[b];
}
int find(int s){
    if(s!=fa[s]) fa[s]=find(fa[s]);
    return fa[s];
}
void dfs(int s,int la,int id){
    for(int i=0;i<x[s].size();i++){
        if(x[s][i]==la||y[s][i]==1) continue;
        if(z[s][i]>a[id][x[s][i]]&&x[s][i]<=n) tot+=z[s][i]-a[id][x[s][i]];
        if(s>n&&z[s][i]>a[id][x[s][i]]){
            sum[s]--;
            if(sum[s]<=1){
                for(int j=0;j<x[s].size();j++){
                    if(x[s][j]==la) tot+=z[s][j];
                }
                tot+=c[s-n];
            }
        }
        dfs(x[s][i],s,id);
    }
}
void df(int s,int la,int id){
    for(int i=0;i<x[s].size();i++){
        if(x[s][i]==la||y[s][i]==1) continue;
        if(z[s][i]>a[id][x[s][i]]&&x[s][i]<=n){
            y[s][i]=1;
            y[x[s][i]][f[s][i]-1]=1;
            x[n+id].push_back(x[s][i]);
            y[n+id].push_back(0);
            z[n+id].push_back(a[id][x[s][i]]);
            f[n+id].push_back(x[x[s][i]].size()+1);
            x[x[s][i]].push_back(n+id);
            y[x[s][i]].push_back(0);
            z[x[s][i]].push_back(a[id][x[s][i]]);
            f[x[s][i]].push_back(x[n+id].size());
        }
        if(s>n&&z[s][i]>a[id][x[s][i]]){
            if(sum[s]<=1){
                for(int j=0;j<x[s].size();j++){
                    if(x[s][j]==la){
                        y[s][j]=1;
                        y[x[s][j]][f[s][j]-1]=1;
                    }
                }
            }
        }
        df(x[s][i],s,id);
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        r[i]=i;
    }
    sort(r+1,r+m+1,cmp);
    for(int i=1;i<=m;i++){
        int o=find(u[r[i]]),p=find(v[r[i]]);
        if(fa[o]!=fa[p]){
            x[u[r[i]]].push_back(v[r[i]]);
            z[u[r[i]]].push_back(w[r[i]]);
            y[u[r[i]]].push_back(0);
            f[u[r[i]]].push_back(x[v[r[i]]].size()+1);
            x[v[r[i]]].push_back(u[r[i]]);
            z[v[r[i]]].push_back(w[r[i]]);
            y[v[r[i]]].push_back(0);
            f[v[r[i]]].push_back(x[u[r[i]]].size());
            fa[o]=p;
            ans+=w[r[i]];
        }
    }
    //cout<<ans<<endl;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        int k=0;
        a[i][0]=3000000009;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]<=a[i][k]){
                k=j;
            }
        }
        tot=0;
        dfs(k,0,i);
        if(tot<=c[i]+a[i][k]) continue;
        x[n+i].push_back(k);
        z[n+i].push_back(a[i][k]);
        y[n+i].push_back(0);
        f[n+i].push_back(x[k].size()+1);
        x[k].push_back(n+i);
        z[k].push_back(a[i][k]);
        y[k].push_back(0);
        f[k].push_back(x[n+i].size()+1);
        df(k,n+i,i);
        ans-=(tot-c[i]-a[i][k]);
        sum[i+n]=x[i+n].size();
    }
    cout<<ans<<endl;
    return 0;
}