#include <bits/stdc++.h>
using namespace std;
int T,n,x,y,z,p[3][100005],cnt[3],tot[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        cnt[0]=cnt[1]=cnt[2]=tot[0]=tot[1]=tot[2]=0;
        scanf("%d",&n); long long ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&x,&y,&z);
            if(x>=y&&x>=z){
                cnt[0]++,ans+=x;
                p[0][++tot[0]]=x-max(y,z);
            }else if(y>=x&&y>=z){
                cnt[1]++,ans+=y;
                p[1][++tot[1]]=y-max(x,z);
            }else{
                cnt[2]++,ans+=z;
                p[2][++tot[2]]=z-max(y,x);
            }
        }
        for(int i=0;i<=2;i++) if(cnt[i]>n/2){
            sort(p[i],p[i]+tot[i]+1);
            for(int j=1;j<=cnt[i]-n/2;j++) ans-=p[i][j];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
