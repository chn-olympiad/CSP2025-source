#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=3e6+5;
int n,m,k;
struct E{
    int u,v,w;
}e[M];
vector<pair<int ,int>> g[N];
int a[15][N];
int c[15];
bool cmp(E x,E y){
    return x.w<y.w;
}
int f[N];
void iint(){
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
}
int ans=0;
int find(int x){
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
void dfs(int x,int fa){
    for(int i=0;i<g[x].size();i++){
        int v=g[x][i].first,w=g[x][i].second;
        if(v==fa) continue;
        ans+=w;
        dfs(v,x);
    }
    return ;
}

void subtask1(){
    iint();
    sort(e+1,e+m+1,cmp);
  //  cout<<"yes"<<" "<<m<<endl;
    for(int i=1;i<=m;i++){
        int u=find(e[i].u),v=find(e[i].v);
    //    cout<<e[i].u<<" "<<e[i].v<<endl;
        if(u!=v){
            f[u]=v;
            g[e[i].u].push_back(make_pair(e[i].v,e[i].w));
            g[e[i].v].push_back(make_pair(e[i].u,e[i].w));
        }
    }
 //   cout<<"yes"<<endl;
    dfs(1,-1);
    cout<<ans<<endl;
}
int d[15];
void subtask2(){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
 //           cout<<a[i][j]<<" ";
            if(a[i][j]==0){
                d[i]=j;
                break;
            }
        }

    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(j==d[i]){
                continue;
            }
            e[++m].u=d[i];
            e[m].v=j;
            e[m].w=a[i][j];
        }

    }
 //   cout<<" yes "<<endl;
    subtask1();
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    bool sb2=false;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]>0) sb2=true;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
 //   for(int i=1;i<=m;i++){
  //      cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;

  //  }
    if(k==0) subtask1();
    else if(sb2==false){
        subtask2();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}


