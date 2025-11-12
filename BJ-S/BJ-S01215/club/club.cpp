#include<bits/stdc++.h>
using namespace std;
int n,a[100010][4];
long long ans=-1;
void dfs(int id,int x,int y,int z,long long tot){
    if(id==n+1){
        ans=max(ans,tot);
        return;
    }
    for(int i=1;i<=3;i++){
        if(i==1&&x+1<=n/2) dfs(id+1,x+1,y,z,tot+a[i][id]);
        if(i==2&&y+1<=n/2) dfs(id+1,x,y+1,z,tot+a[i][id]);
        if(i==3&&z+1<=n/2) dfs(id+1,x,y,z+1,tot+a[i][id]);
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        ans=-1;
        scanf("%d",&n);
        int pf=0,max1=-1,max2=-1;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
            if(a[2][i]==0&&a[3][i]==0){
                pf++;
            }
        }
        if(pf==n){
            sort(a[1]+1,a[1]+n+1);
            printf("%d\n",a[1][n-1]+a[1][n]);
            continue;
        }
        if(n>=100000){
            sort(a[1]+1,a[1]+n+1);
            sort(a[2]+1,a[2]+n+1);
            sort(a[3]+1,a[3]+n+1);
            for(int i=1;i<=n/2+1;i++){
                ans+=a[1][n-i+1]+a[2][n-i+1]+a[3][n-i+1]-(a[1][i]+a[2][i]+a[3][i]);
            }
            printf("%lld\n",ans);
            continue;
        }
        dfs(1,0,0,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
