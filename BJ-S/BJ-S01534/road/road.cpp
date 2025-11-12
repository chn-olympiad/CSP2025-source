#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,k,re=100000000;
int fa[50005],c[15][5000005];
bool b[15];
struct l{
    int u,v,w;
};
vector <l> lu(1);
bool cmp(l &a,l &b){
    return a.w<b.w;
}
int f(int x){
    return fa[x]==x?x:fa[x]=f(fa[x]);
}
void un(int x,int y){
    int fx=f(x),fy=f(y);
    if(fx==fy)
        return;
    fa[fx]=fy;
}
bool is(int x,int y){
    int fx=f(x),fy=f(y);
    return fx==fy;
}
void dfs(int d,int now){
    if(d>k){
        vector <l> lu1(1);
        for(int i=0;i<=n+k;i++)
            fa[i]=i;
        for(int i=1;i<=k;i++)
            if(b[i])
                for(int j=1;j<=n;j++)
                    lu1.push_back({i+n,j,c[i][j]});
        for(int i=1;i<=m;i++)
            lu1.push_back(lu[i]);
        sort(lu1.begin()+1,lu1.end(),cmp);
        for(int i=1;i<lu1.size();i++){
            if(!is(lu1[i].u,lu1[i].v)){
                un(lu1[i].u,lu1[i].v);
                now+=lu1[i].w;
            }
        }
        re=min(re,now);
        return;
    }
    b[d]=1;
    now+=c[d][0];
    dfs(d+1,now);
    b[d]=0;
    now-=c[d][0];
    dfs(d+1,now);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<=n+k;i++)
        b[i]==0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        lu.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i][0];
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    dfs(1,0);
    cout<<re<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

