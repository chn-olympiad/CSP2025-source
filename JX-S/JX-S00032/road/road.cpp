#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e6+5,K=15;
bool flag=true;
int n,m,k,c[N],xc[K][N],a[N][N],b[N][N];

int js;
struct node{
    int u,v,w;
}ku[M];
int fa[N];
bool cmp(node A,node B){
    return A.w<B.w;
}
int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
node bf[M];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    memset(a,0x3f,sizeof a);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ku[++js]={u,v,w};
        ku[++js]={v,u,w};
        a[u][v]=min(a[u][v],w);
        a[v][u]=min(a[v][u],w);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        c[i]!=0?flag=false:true;
        for(int j=1;j<=n;j++) cin>>xc[i][j];
    }

    if(k==0){//kulus
        long long ansB=0;
        sort(ku+1,ku+js+1,cmp);
        for(int i=0;i<=N+1;i++) fa[i]=i; 
        for(int i=1;i<=js;i++){
            int faa=find(ku[i].u),fab=find(ku[i].v);
            if(faa!=fab){
                fa[faa]=fab;
                ansB+=ku[i].w;
            }
        }
        cout<<ansB<<'\n';
        return 0;
    }

    if(flag){//A
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                for(int op=j+1;op<=n;op++){
                    a[j][op]=min(xc[i][j]+xc[i][op],a[j][op]);
                    // cout<<j<<' '<<op<<' '<<xc[i][j]+xc[i][op]<<'\n';
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]!=0x3f3f3f3f&&i!=j) ku[++js]={i,j,a[i][j]},ku[++js]={j,i,a[i][j]};
            }
        }
        // for(int i=1;i<=n;i++){
            // cout<<ku[i].u<<' '<<ku[i].v<<' '<<ku[i].w<<'\n';
        // }
        long long ansA=0;
        sort(ku+1,ku+js+1,cmp);
        for(int i=0;i<=N+1;i++) fa[i]=i; 
        for(int i=1;i<=js;i++){
            int faa=find(ku[i].u),fab=find(ku[i].v);
            if(faa!=fab){
                fa[faa]=fab;
                ansA+=ku[i].w;
            }
        }
        cout<<ansA<<'\n';
        return 0;
    }
    long long ans=INT_MAX;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) b[i][j]=a[i][j];
    for(int i=1;i<=js;i++) bf[i]=ku[i];
    for(int K=0;K<(1<<k);K++){
        int opjs=js;
        for(int i=1;i<=opjs;i++) ku[i]=bf[i];
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=b[i][j];
        long long sum=0;
        for(int j=0;j<k;j++){
            // cout<<(K>>j&1)<<' '<<K;
            if(K>>j&1){
                sum+=c[j+1];
                for(int l=2;l<=n;l++){
                    for(int r=1;r<l;r++){
                        a[l][r]=min(xc[j+1][l]+xc[j+1][r],a[l][r]);
                    }
                }
            }
            // cout<<'\n';
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]!=0x3f3f3f3f&&i!=j) ku[++opjs]={i,j,a[i][j]},ku[++opjs]={j,i,a[i][j]};
            }
        }
        sort(ku+1,ku+opjs+1,cmp);
        for(int i=0;i<=N+1;i++) fa[i]=i; 
        for(int i=1;i<=opjs;i++){
            int faa=find(ku[i].u),fab=find(ku[i].v);
            if(faa!=fab){
                fa[faa]=fab;
                sum+=ku[i].w;
            }
        }
        ans=min(ans,sum);
    }
    cout<<ans<<'\n';
    return 0;
}