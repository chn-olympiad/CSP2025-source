#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,t[10015],fa[10015],cnt;
struct edge{
    int u,v,w;
}a[10015];
bool v[10015];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
int find(int u){
    if(fa[u]==u) return u;
    return fa[u]=find(fa[u]);
}
bool same(int x,int y){
    return find(x)==find(y);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return ;
    fa[x]=y;
}
bool sameall(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!same(i,j)) return false;
        }
    }
    return true;
}
int kru(){
    int ans=0;
    init();
    sort(a+1,a+cnt+1,cmp);
    /*
    for(int i=1;i<=cnt;i++){
        cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
    }
    */
    for(int i=1;i<=cnt;i++){
        if(sameall()) return ans;
        if(!same(a[i].u,a[i].v)){
            unite(a[i].u,a[i].v);
            if(a[i].u>n&&!v[a[i].u]){
                v[a[i].u]=true;
            }else if(a[i].u>n&&v[a[i].u]){
                ans-=t[a[i].u];
            }
            if(a[i].v>n&&!v[a[i].v]){
                v[a[i].v]=true;
            }else if(a[i].v>n&&v[a[i].v]){
                ans-=t[a[i].v];
            }
            //cout<<a[i].u<<" "<<a[i].v<<" ";
            ans+=a[i].w;
            //cout<<ans<<endl;
        }
    }
    return ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    cnt=m;
    bool flag=true;
    for(int i=1;i<=k;i++){
        cin>>t[i+n];
        if(t[i+n]!=0) flag=false;
        for(int j=1,l;j<=n;j++){
            cin>>l;
            if(l!=0) flag=false;
            a[++cnt]={i+n,j,t[i+n]+l};
        }
    }
    if(flag){
        cout<<0<<endl;
        return 0;
    }
    int tmp=kru();
    cout<<tmp<<" ";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
