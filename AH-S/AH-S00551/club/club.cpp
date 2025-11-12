#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=5000;
int t,n,cnt[5];
int a[N][3];
int f[M][M];
struct stu{
    int u,v;
}b[N];
bool cmp(stu x,stu y){
    return x.u-x.v>y.u-y.v;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bool flag=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
            }
            if(a[i][3]!=0) flag=1;
        }
        if(!flag){
            int cnt1=0,cnt2=0;
            for(int i=1;i<=n;i++){
                b[i]={a[i][1],a[i][2]};
            }
            sort(b+1,b+n+1,cmp);
            int ans=0;
            for(int i=1;i<=n;i++){
                if(i<=n/2){
                    ans+=b[i].u;
                }else{
                    ans+=b[i].v;
                }
            }
            printf("%d\n",ans);
            continue;
        }
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            for(int j=min(n/2,i);j>=0;j--){
                for(int k=min(n/2,i-j);k>=0;k--){
                    if(i-j-k>n/2){
                        continue;
                    }
                    if(i-j-k>=1){
                        f[j][k]=max(f[j][k],f[j][k]+a[i][3]);
                    }
                    if(j>=1){
                        f[j][k]=max(f[j][k],f[j-1][k]+a[i][1]);
                    }
                    if(k>=1){
                        f[j][k]=max(f[j][k],f[j][k-1]+a[i][2]);
                    }
                }
            }
        }
        int ans=0;
        for(int j=0;j<=n/2;j++){
            for(int k=0;k<=n/2;k++){
                ans=max(ans,f[j][k]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
