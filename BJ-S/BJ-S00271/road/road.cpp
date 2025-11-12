#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[10100],cnt;
long long ans;
struct le{
    long long id,to,v;
}a[2500000];
bool cmp(le x,le y){
    return x.v<y.v;
}
int find(long long x){
    if(fa[x]==x)return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void kl(){
    for(int i=1;i<=n+k+1;i++)fa[i]=i;
    sort(a+1,a+cnt+1,cmp);
    int kp=0;
    for(int i=1;i<=cnt;i++){
        if(find(a[i].id)!=find(a[i].to)){
            fa[find(a[i].id)]=fa[find(a[i].to)];
            ans+=1ll*a[i].v;
        }
    }
}
signed main(){
    memset(a,0,sizeof(a));
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,v;
        cin>>x>>y>>v;
        le xx,yy;
        xx.id=x,xx.to=y,xx.v=v;
        yy.id=y,yy.to=x,yy.v=v;
        a[++cnt]=xx;
        a[++cnt]=yy;
    }
    for(int i=1;i<=k;i++){
        int w;
        cin>>w;
        for(int j=1;j<=n;j++){
            long long v;
            cin>>v;
            a[++cnt]={n+i,j,v};
            a[++cnt]={j,n+i,v};
        }
    }
    kl();
    cout<<ans;
    return 0;
}
