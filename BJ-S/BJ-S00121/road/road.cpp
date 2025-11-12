#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int N=1e4+5;
struct road{
    int u,v,w;
}e[20000005];
int fa[N];
int e1[15][N],e2[N][15];
int w[105];
bool cmp(road r1,road r2){
    return r1.w<r2.w;
}
int fd(int u){
    if(u==fa[u]) return u;
    else return fa[u]=fd(fa[u]);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>w[i];
        for(int j=1;j<=n;j++){
            cin>>e1[i][j];
            e2[j][i]=e1[i][j];
        }
    }
    if(k!=0){
        for(int i=1;i<=n;i++){
        fa[i]=i;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            for(int p=1;p<=k;p++){
                //cout<<m<<endl;
                e[++m].u=i;
                e[m].v=j;
                e[m].w=e2[i][p]+e1[p][j];
            }

        }
    }
    }

    sort(e+1,e+m+1,cmp);
    int cnt=0,sum=0;
    for(int i=1;i<=m;i++){
        int fa1=fd(e[i].u),fa2=fd(e[i].v);
        if(fa1==fa2) continue;
        sum+=e[i].w;
        fa[fa1]=fa2;
        cnt++;
        if(cnt==n-1) break;
    }
    cout<<sum;
    return 0;
}
