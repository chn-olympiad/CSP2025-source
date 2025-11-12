#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005],qq[10005];
struct ss{
    int u,v,w;
}g[1000005];
bool cmp(ss x,ss y){
    return x.w<y.w;
}
struct node{
    int u,v,w;
    bool operator >(const node x)const{
        return w>x.w;
    }
};
priority_queue<node,vector<node>,greater<node> > q;
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    x=find(x),y=find(y);
    fa[x]=y;
}
bool same(int x,int y){
    return find(x)==find(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,a,b,c;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        g[i].u=a;
        g[i].v=b;
        g[i].w=c;
        q.push((node){a,b,c});
    }
    init();
    if(k==0){
        sort(g+1,g+m+1,cmp);
        int cnt=0;
        long long ans=0;
        for(int i=1;i<=m;i++){
            ss t=g[i];
            if(!same(t.u,t.v)){
                unite(t.u,t.v);
                cnt++;
                ans+=t.w;
            }
            if(cnt==n-1){
                cout<<ans;
                break;
            }
        }
    }else{
        for(int i=1;i<=k;i++){
            for(int i=0;i<=n;i++){
                cin>>qq[i];
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    q.push({i,j,qq[i]+qq[j]+qq[0]});
                }
            }
        }
        int cnt=0;
        long long ans=0;
        while(cnt!=n-1){
            node t=q.top();q.pop();
            if(!same(t.u,t.v)){
                unite(t.u,t.v);
                cnt++;
                ans+=t.w;
            }
        }
        cout<<ans;
    }
    return 0;
}
