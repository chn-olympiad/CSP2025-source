#include<bits/stdc++.h>
using namespace std;
const int M=1e6+1e5+20,N=1e4+20;
int n,m,k,cnt,fa[N],f[20],l[20];
long long ans=1e18;
struct node{
    int l,r,cur,t;
}a[M];
bool cmp(node a,node b){
    return a.cur<b.cur;
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    cnt=m;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].cur);
        a[i].t=0;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&f[i]);
        for(int j=1;j<=n;j++){
            cnt++;
            scanf("%d",&a[cnt].cur);
            a[cnt].l=i+n,a[cnt].r=j,a[cnt].t=i;
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int g=0;g<(1<<k);g++){
        int v=g,now=0,sum=0,som=0;
        long long nans=0;
        while(v){
            l[++now]=v&1;
            sum+=l[now];
            nans+=l[now]*f[now];
            v/=2;
        }
        for(int i=1;i<=n+k;i++)fa[i]=i;
        for(int i=1;i<=cnt;i++){
            if(l[a[i].t]==1||a[i].t==0){
                int fx=find(a[i].l),fy=find(a[i].r);
                if(fx==fy)continue;
                fa[fx]=fy;
                som++;
                nans+=a[i].cur;
                if(som==n+sum-1)break;
            }
        }
        ans=min(nans,ans);
    }
    printf("%lld",ans);
    return 0;
}
