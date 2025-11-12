#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1010,M=1000010;
struct node{
    int x,y,z;
}e[N*N>>1];
int n,m,k,x,y,z,cnt;
int a[N][N];
int b[N];
int fa[N];
int find(int x){
    return (fa[x]==x?x:fa[x]=find(fa[x]));
}
bool cmp(node x,node y){
    return x.z<y.z;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    memset(a,0x3f,sizeof(a));
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        a[x][y]=min(a[x][y],z);
        a[y][x]=a[x][y];
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&x);
        for(int j=1;j<=n;j++){
            scanf("%lld",&b[j]);
            for(int p=1;p<j;p++){
                if(x+b[p]+b[j]<a[p][j]){
                    a[p][j]=x+b[p]+b[j];
                    a[j][p]=x+b[p]+b[j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            e[++cnt]={i,j,a[i][j]};
        }
    }
    sort(e+1,e+cnt+1,cmp);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int s=0,ans=0;
    for(int i=1;i<=cnt;i++){
        if(find(e[i].x)!=find(e[i].y)){
            fa[find(e[i].x)]=find(e[i].y);
            s++;
            ans+=e[i].z;
            if(s==n-1){
                printf("%lld",ans);
                return 0;
            }
        }
    }
    return 0;
}
