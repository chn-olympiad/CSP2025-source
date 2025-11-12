#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 0.5e4+10;
ll n,m,k,x,y,len,p[N],num,fa[N],ans,numi,vis[N];
bool flag=false;
int dis[N][N];
struct node{
    int from,to,len;
}a[N*N-N];
bool cmp(node n1,node n2){
    return n1.len<n2.len;
}
ll find(ll x){
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i = 1;i <= n;i++) fa[i]=i;
    for(ll i = 1;i <= n;i++){
        for(ll j = 1;j <= n;j++){
            dis[i][j]=1e9+10;
        }
    }
    for(ll i = 1;i <= n;i++) dis[i][i]=0;
    for(ll i = 1;i <= m;i++){
        scanf("%lld%lld%lld",&x,&y,&len);
        dis[x][y]=min(dis[x][y],(int)len);
        dis[y][x]=min(dis[y][x],(int)len);
    }
    for(ll i = 1;i <= k;i++){
        scanf("%lld",&numi);
        if(numi) flag=true;
        for(ll j = 1;j <= n;j++){
            scanf("%lld",&p[j]);
            if(p[j]) flag=true;
        }
        for(ll j = 1;j <= n;j++){
            for(ll r = 1;r <= n;r++){
                if(j==r) continue;
                if(!vis[i]&&p[j]+p[r]+numi<dis[j][r]){
                    dis[j][r]=p[j]+p[r];
                    ans+=numi;
                    vis[i]=true;
                }
                if(vis[i]&&p[j]+p[r]<dis[j][r]){
                    dis[j][r]=p[j]+p[r];
                }
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i!=j&&dis[i][j]!=3e9+10){
                a[++num]={i,j,dis[i][j]};
            }
        }
    }
    ll cnt=0;
    sort(a+1,a+num+1,cmp);
    for(ll i = 1;i <= num;i++){
        ll x=a[i].from,y=a[i].to,len=a[i].len;
        if(find(x)!=find(y)){
            fa[find(x)]=find(y);
            ans+=len;
            cnt++;
            if(cnt==n-1) break;
        }
    }
    if(flag) printf("%lld",ans);
    else printf("0");
    return 0;
}
