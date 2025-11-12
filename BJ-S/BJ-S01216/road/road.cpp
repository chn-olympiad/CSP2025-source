#include<bits/stdc++.h>
using namespace std;
#define maxn 50005
#define maxm 2000005
#define int long long
struct edge{
    int u,v,w;
    bool operator<(const edge rhs)const{
        return w<rhs.w;
    }
}e[maxm];
int n,m,k,fa[maxn],c[20],lstf,cntl,ans=0x3f3f3f3f3f3f3f3fll;
bool era[maxn];
int get(int x){
    if(fa[x]==x){
        return x;
    }
    fa[x]=get(fa[x]);
    return fa[x];
}
bool merg(int x,int y){
    x=get(x);
    y=get(y);
    if(x==y){
        return false;
    }
    fa[x]=y;
    return true;
}
int lst(void){
    int cnt=cntl-1,ret=0;
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m+n*k;i++){
        if(era[e[i].u]||era[e[i].v]){
            continue;
        }
        if(merg(e[i].u,e[i].v)){
            cnt--;
            ret+=e[i].w;
            if(!cnt){
                return ret;
            }
        }
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    cntl=n+k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            e[m+(i-1)*n+j].u=n+i;
            e[m+(i-1)*n+j].v=j;
            cin>>e[m+(i-1)*n+j].w;
        }
    }
    sort(e+1,e+m+n*k+1);
    for(int i=0;i<(1<<k);i++){
        int sum=0;
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1){
                cntl--;
                era[n+j]=true;
            }
            else{
                sum+=c[j];
            }
        }
        ans=min(ans,lst()+sum);
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1){
                cntl++;
                era[n+j]=false;
            }
        }
    }
    cout<<ans;
    return 0;
}
