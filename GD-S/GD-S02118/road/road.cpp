#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int fat[10091];
int t[15];
int n,m,k;
long long ans = 0;
int find(int x){
    if (fat[x]==x) return x;
    return fat[x]=find(fat[x]);
}
void merge(int x,int y){
    fat[find(x)]=find(y);
}
struct edge{
    int u,v,w;
    bool di=0;
};
vector<edge> v;
bool cmp(edge a,edge b){
    return a.w<b.w;
}

long long solve(){
    for (int i = 1;i<=n+k+1;i++) fat[i]=i;
    long long cnt = 0;
    long long ctt = 0;
    sort(v.begin(),v.end(),cmp);
    for (int i = 0;i<v.size();i++){
        if (v[i].di) continue;
        int nu=v[i].u,nv=v[i].v,nw=v[i].w;
        if (find(nu)==find(nv)) continue;
        cnt+=nw;
        merge(nu,nv);
    }
    return cnt;
}
long long jz;
long long dfs(int now){
    if (now==k){
        return solve();
    }
    long long ret = 2427242724272427;
    if (t[now+1]!=-1){
        for (int i = 0;i<v.size();i++){
            if (v[i].u==n+now+1){
                v[i].di = 0;
            }
        }
        ret = min(ret,t[now+1]+dfs(now+1));
    }
    if (t[now+1]!=-2){
        for (int i = 0;i<v.size();i++){
            if (v[i].u==n+now+1){
                v[i].di = 1;
            }
        }
        ret = min(ret,dfs(now+1));
    }
    return ret;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1;i<=m;i++){
        edge temp;
        cin >> temp.u >> temp.v >> temp.w;
        v.push_back(temp);
    }
    bool planb = 1;
    for (int i = 1;i<=k;i++){
        cin >> t[i];if (t[i]!=0) planb=0;
        for (int j = 1;j<=n;j++){
            edge temp;temp.u = n+i,temp.v = j;temp.di = 1;
            cin >> temp.w;
            v.push_back(temp);
        }
    }
    if (planb){
        for (int i = 0;i<v.size();i++){
            if (v[i].u>n){
                v[i].di = 0;
            }
        }
        cout << solve();
        return 0;
    }
    jz=solve();
    for (int i = 1;i<=k;i++){
        if (t[i]>jz) t[i]=-1;
    }
    cout << dfs(0);
}