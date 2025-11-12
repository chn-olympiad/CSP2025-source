#include <bits/stdc++.h>
using namespace std;
int t,n,p,x,ax,bx,cx;
long long ans;
int a[100010],b[100010],c[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            if(b[i]==0&&c[i]==0){
                p++;
            }
            if(c[i]==0){
                x++;
            }
        }
        ax=0;
        bx=0;
        cx=0;
        ans=0;
        if(n==2){
            int o=a[1]+b[2],l=a[1]+c[2],z=b[1]+a[2],v=b[1]+c[2],h=c[1]+b[2],g=c[1]+a[2];
            printf("%d\n",max(o,max(l,max(z,max(v,max(h,g))))));
            return 0;
        }
        if(p==n){
            sort(a+1,a+1+n);
            for(int i=n;i>=n/2+1;i--){
                ans+=a[i];
            }
            printf("%lld\n",ans);
            return 0;
        }
        for(int i=1;i<=n;i++){
            if(a[i]>=b[i]&&a[i]>=c[i]&&ax<n/2){
                ans+=a[i];
                ax++;
            }
            if(b[i]>=a[i]&&b[i]>=c[i]&&bx<n/2){
                ans+=b[i];
                bx++;
            }
            if(c[i]>=a[i]&&c[i]>=b[i]&&cx<n/2){
                ans+=c[i];
                cx++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
