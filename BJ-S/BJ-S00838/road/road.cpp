#include<bits/stdc++.h>
#define N 20005
#define int long long
using namespace std;
int c1[30];
int a[30][N];
struct node{
    int u,v,w;
}b[4000005];
node c[4000005];
bool cmp(node a,node b){
    return a.w<b.w;
}
int fa[N];
int find(int u){
    if(u==fa[u])return u;
    else return fa[u]=find(fa[u]);
}
bool vis[4000005];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>b[i].u>>b[i].v>>b[i].w;
    }
    sort(b+1,b+1+m,cmp);
    for(int i=1;i<=n+15;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x=find(b[i].u),y=find(b[i].v);
        if(x!=y){
            fa[x]=y;
            vis[i]=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(vis[i]==1){
            c[++cnt]=b[i];
        }
    }
    for(int i=1;i<=k;i++){
        cin>>c1[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    //for(int i=1;i<=cnt;i++){
    //    cout<<c[i].u<<" "<<c[i].v<<" "<<c[i].w<<endl;
    //}
    int mmin=1e16;
    for(int o=0;o<(1<<k);o++){
        for(int i=1;i<=cnt;i++){
            b[i]=c[i];
        }
        int h=cnt;
        int ans=0;
        for(int j=1;j<=k;j++){
            if((o&(1<<(j-1)))){
                ans+=c1[j];
                for(int p=1;p<=n;p++){
                    h++;
                    b[h].u=n+j;
                    b[h].v=p;
                    b[h].w=a[j][p];
                }
            }
        }
        int ssum=0;
        sort(b+1,b+1+h,cmp);
        for(int i=1;i<=n+15;i++){
            fa[i]=i;
        }
        for(int i=1;i<=h;i++){
            int x=find(b[i].u),y=find(b[i].v);
            if(x!=y){
                fa[x]=y;
                ssum+=b[i].w;
            }
        }
        //cout<<"o:"<<o<<" "<<ssum<<" "<<ans<<endl;
        mmin=min(mmin,ssum+ans);
    }
    cout<<mmin<<endl;
    return 0;
}
