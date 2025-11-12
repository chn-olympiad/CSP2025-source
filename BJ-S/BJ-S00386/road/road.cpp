#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
long long  n,m,k,ans=0;
struct node{
    int u,v,w;
}e[M+10*N],ne[M+10*N];
int f[N+10],c[15],ned[15][N],cnt;
int find(int x){
    if(f[x]==x) return x;
    else return f[x]=find(f[x]);
}
bool cmp(node x,node y){
    return x.w<y.w;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>ned[i][j];
        }
    }
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(cnt==n-1) break;
        if(find(e[i].u)!=find(e[i].v)){
            cnt++;
            f[find(e[i].u)]=find(e[i].v);
            ans+=e[i].w;
        }
    }
    if(cnt!=n-1) ans=INT_MAX;
    for(int tmp=0;tmp<(1<<k);tmp++){
        long long siz=m,tans=0;
        for(int j=1;j<=m;j++){
            ne[j]=e[j];
        }
        for(int j=1;j<=n+k;j++){
            f[j]=j;
        }
        cnt=0;
        int cnt1=0;
        for(int i=0;i<k;i++){
            if((tmp>>i)&1){
                for(int j=1;j<=n;j++){
                    siz++;
                    ne[siz].u=n+i+1;
                    ne[siz].v=j;
                    ne[siz].w=ned[i+1][j];
                }
                cnt1++;
                tans+=c[i+1];
            }
        }
        sort(ne+1,ne+1+siz,cmp);
        for(int j=1;j<=siz;j++){
            if(cnt==n+cnt1-1) break;
            if(find(ne[j].u)!=find(ne[j].v)){
                f[find(ne[j].u)]=find(ne[j].v);
                tans+=ne[j].w;
                cnt++;
            }
        }
        if(cnt==n+cnt1-1) ans=min(ans,tans);
    }
    cout<<ans<<'\n';
    return 0;
}

