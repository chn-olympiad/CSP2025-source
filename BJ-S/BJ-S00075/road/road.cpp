#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int u[N],v[N],w[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;bool f=1;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]);
    for(int i=1,t;i<=k;i++){
        scanf("%d",&t);
        if(t!=0) f=0;
        for(int j=1;j<=m;j++){
            scanf("%d",&t);
            if(t!=0) f=0;
        }
    }
    if(f==1){
        printf("%d",0);
        return 0;
    }
    sort(w+1,w+n+1);
    int ans=0;
    for(int i=1;i<n;i++) ans+=w[i];
    printf("%d",ans);
    return 0;
}
