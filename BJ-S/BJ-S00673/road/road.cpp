#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int n,m,k,x,y,z,t[11451],a;
long long ans;
int v[11451][11451];
void dj(int x){

}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    memset(v,0x3f,sizeof v);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&x,&y,&z);
        v[x][y]=v[y][x]=z;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&a);
        for(int j=1;j<=n;j++){
            scanf("%d",t+j);
            for(int l=j-1;l>0;l--){
                v[l][j]=v[j][l]=min(t[j]+t[k]+a,v[j][l]);
            }
        }
    }
    dj(1);
    printf("%lld",ans);
}
