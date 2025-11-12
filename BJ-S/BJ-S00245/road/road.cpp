#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+20,M=1e6+10,inf=2e16;
int n,m,k,fa[N],c[N],tot,ans;
struct node{
    int u,v,w;
    bool operator<(const node&b)const{
        return w<b.w;
    }
}bian[M],a[12][N],b[1025][N];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int szof(int x){
    int rt=0;
    while(x!=0){
        rt+=x%2;
        x/=2;
    }
    return rt;
}
void dfs(int x,int lst,int lstjia){
    if(x>k) return ;
    int l1=1,l2=1,xuan=0;
    int sz1=n+szof(lst)-1,sz2=n;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    int mn=lstjia+c[x];
    while(xuan<=sz1){
        node tmp;
    //    cout<<"i "<<x<<" "<<lst<<" "<<xuan<<" "<<l1<<" "<<l2<<endl;
    //    if(l1==5) exit(0);
        if(l1>sz1||((l2<=sz2)&&(b[lst][l1].w>=a[x][l2].w))){
            tmp=a[x][l2];
            int u=tmp.u,v=tmp.v,w=tmp.w;
            int uu=find(u),vv=find(v);
            if(uu!=vv){
                fa[uu]=vv;
                b[lst+(1<<(x-1))][++xuan]={u,v,w};
            //    cout<<"uvw "<<u<<" "<<v<<" "<<w<<endl;
                mn+=w;
            }
            l2++;
        }else{
            tmp=b[lst][l1];
            int u=tmp.u,v=tmp.v,w=tmp.w;
            int uu=find(u),vv=find(v);
            if(uu!=vv){
                fa[uu]=vv;
                b[lst+(1<<(x-1))][++xuan]={u,v,w};
                mn+=w;
            }
            l1++;
        }
    }
    ans=min(ans,mn);
    dfs(x+1,lst+(1<<(x-1)),lstjia+c[x]);
    dfs(x+1,lst,lstjia);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        bian[i]={x,y,z};
    }
    sort(bian+1,bian+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    int mn=0;
    for(int i=1;i<=m;i++){
        if(tot>=n-1) break;
        int u=bian[i].u,v=bian[i].v,w=bian[i].w;
        int uu=find(u),vv=find(v);
        if(uu!=vv){
            fa[uu]=vv;
            b[0][++tot]={u,v,w};
            mn+=w;
        }
    }
    ans=mn;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            a[i][j]={i+n,j,x};
        }
        sort(a[i]+1,a[i]+n+1);
    }
    dfs(1,0,0);
    cout<<ans<<endl;
    return 0;
}