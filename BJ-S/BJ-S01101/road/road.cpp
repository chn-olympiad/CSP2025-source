#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
    int u,v,w;
}e[9000001];
int fa[10001];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int f(int x){
    if(fa[x]==x){
        return x;
    }
    fa[x]=f(fa[x]);
    return fa[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    int cnt=n;
    for(int i=1;i<=k;i++){
        int c,w[10001];
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>w[j];
        }
        for(int x=1;x<=n;x++){
            for(int y=x+1;y<=n;y++){
                if(x==y){
                    continue;
                }
                cnt++;
                e[cnt].u=x;
                e[cnt].v=y;
                e[cnt].w=w[x]+w[y];
            }
        }
    }
    sort(e+1,e+cnt+1,cmp);
    unsigned long long ans=0,cnt2=0;
    for(int i=1;i<=cnt;i++){
        int x=f(e[i].u);
        int y=f(e[i].v);
        if(x!=y){
            fa[x]=y;
            ans+=e[i].w;
            cout<<e[i].u<<"->"<<e[i].v<<" "<<e[i].w<<endl;
            cnt2++;
        }
        if(cnt2==n-1){
            break;
        }
    }
    cout<<ans;
    return 0;
}
