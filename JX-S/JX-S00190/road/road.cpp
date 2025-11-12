#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
const int M=1e6+10;
const int K=12;
int n,m,k;
int fa[N*10];
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
struct Edge{
    int next;
    int to;
    ll w;
}edge[2*N*K+M*2];

bool cmp(Edge u1,Edge u2){
    return u1.w<u2.w;
}

void ku(){
    ll ans=0;
    int u=0;
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(u==n-1) break;
        int x=edge[i].next;
        int y=edge[i].to;
        x=find(x);
        y=find(y);
        if(x==y) continue;
        fa[x]=y;
        ans+=edge[i].w;
        u++;
    }
    cout<<ans;
}


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>edge[i].next>>edge[i].to>>edge[i].w;
    }
    if(k==0){
        for(int i=1;i<=n;i++) fa[i]=i;
        ku();
        return 0;
    }

    for(int i=1;i<=k;i++){
        int cj;
        cin>>cj;
        for(int j=1;j<=n;j++){
            edge[++m].next=n+i;
            edge[m].to=j;
            cin>>edge[m].w;
        }
    }

    n+=k;
    for(int i=1;i<=n;i++) fa[i]=i;
    ku();
    return 0;
}

