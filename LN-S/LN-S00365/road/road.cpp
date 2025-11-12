#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
}e[200005];
int f[200015];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int ffind(int x){
    if(f[x]==x) return x;
    //cout << "#5\n";
    return f[x]=ffind(f[x]);
}
void fmerge(int x,int y){
    int fx=ffind(x),fy=ffind(y);
    if(fx!=fy){
        f[fx]=fy;
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << "#0\n";
    int n,m,k;
    long long ans=0;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    //cout << "#1\n";
    int p=m+1;
    for(int i=1;i<=k;i++){
        int sss;
        cin >> sss;
        for(int j=1;j<=n;j++){
            e[p].u=j;
            e[p].v=n+i;
            cin >> e[p].w;
            p++;
        }
    }
    //cout << "#2\n";
    sort(e+1,e+p,cmp);
    //cout << "#3\n";
    //for(int i=1;i<p;i++){
    //    cout << e[i].u << " " << e[i].v << " " << e[i].w << "\n";
    //}
    for(int i=1;i<=n+k;i++){
        f[i]=i;
    }
    int pos=1;
    for(int cnt=0;cnt<n+k-1;){
        edge cur=e[pos];
        //cout << cnt << " " << pos << "\n";
        if(ffind(cur.u)==ffind(cur.v)){
            pos++;
            continue;
        }
        fmerge(cur.u,cur.v);
        cnt++;
        pos++;
        ans+=cur.w;
        //cout << cur.w << "\n";
    }
    cout << ans;
    return 0;
}
