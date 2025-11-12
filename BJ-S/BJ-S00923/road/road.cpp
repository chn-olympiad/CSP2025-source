#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+50,M=2e6+5,K=15;
struct Edge{
    int u,v,w;
}e[M];
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
int f[N],c[K];
int a[K][N];
void Build(){
    for(int i=1;i<=n+k;i++){
        f[i]=i;
    }
}
int find(int x){
    if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}
void Merge(int x,int y){
    f[find(x)]=find(y);
}
bool check(int x,int y){
    if(find(x)==find(y))return true;
    else return false;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    Build();
    long long cost=0;
    int cnt=0,id=m;
    for(int j=1;j<=k;j++){
        cin>>c[j];
        for(int i=1;i<=n;i++){
            cin>>a[j][i];
            if(a[j][i]==0){
                if(!check(i,j+n)){
                    Merge(i,j+n);
                    cnt++;
                }
            }else{
                e[++id].u=i,e[id].v=j+n,e[id].w=a[j][i];
            }
        }
    }
    if(cnt==n+k-1){
        cout<<cost;
        return 0;
    }
    for(int j=1;j<=k;j++){
        for(int j2=j+1;j2<=k;j2++){
            e[++id].u=j+n,e[id].v=j2+n,e[id].w=1e9;
        }
    }
    sort(e,e+id+1,cmp);
    /*for(int i=1;i<=id;i++){
        cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
    }*/
    for(int i=1;i<=id;i++){
        if(cnt==n+k-1)break;
        if(check(e[i].u,e[i].v))continue;
        Merge(e[i].u,e[i].v);
        cnt++;
        cost+=e[i].w;
    }
    cout<<cost;
    return 0;
}