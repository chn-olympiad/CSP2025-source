#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,k;
int a[15][10005];
vector<pair<int,int> > mp[10005];
struct edge{
    int u,v,w;
    bool operator <(const edge& n)const{
        return w<n.w;
    }
}e[2000005],ee[1000005];
bool chd[15];
int rd[10050];
int pw[10050];
int c[15];
int ans = 2e18;
int f[10050];
int fin(int x){
    if(f[x]==x)return x;
    return f[x]=fin(f[x]);
}
int ck=0;
int Kul(){
    for(int i = 1; i <= k+n; i++)f[i]=i;
    int res =0;
    sort(e+1,e+m+ck*n+1);
    for(int i = 1; i <= m+ck*n; i++){
        int u = e[i].u,v=e[i].v,w=e[i].w;
        int uu=fin(u),vv=fin(v);
        // cout << u << ' '<< v << ' '<<uu << ' '<<vv<<' '<<i<<endl;
        if(uu!=vv){
            res+=w;
            rd[u]++,rd[v]++;
            pw[u]=pw[v]=w;
            f[uu]=vv;
        }
    }
    return res;
}
void dfs(int x){
    if(x>k){
        int cnt = 0;
        for(int i = 1; i <= m; i++)e[i]=ee[i];
        for(int i = 1; i <= k; i++){
            if(chd[i]){
                for(int j = 1; j <= n; j++){
                    e[m+cnt*n+j]={i+n,j,a[i][j]};
                    // cout << i+n << ' '<< j << ' '<<m+cnt*n+j<<endl;
                }
                cnt++;
            }
        }
        int res = Kul();
        for(int i = 1; i <= k; i++){
            if(chd[i])res+=c[i];
        }
        for(int i = n+1; i <= n+k; i++){
            if(rd[i]==1)res-=pw[i]+c[i-n];
        }
        ans=min(ans,res);
        // cout << res << endl;
        return;
    }
    chd[x]=0;
    dfs(x+1);
    chd[x]=1;
    ck++;
    dfs(x+1);
    chd[x]=0;
    ck--;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m>>k;
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
        e[i]=ee[i]={u,v,w};
    }
    for(int i = 1; i <= k; i++){
        cin>> c[i];
        for(int j = 1; j <= n; j++)cin >> a[i][j];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}//16pts~48pts