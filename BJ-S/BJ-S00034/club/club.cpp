#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,t,a[N][3],b[N],sum2=0,sum3=0,ans=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        sum2=0,sum3=0,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
            sum2+=a[i][1],sum3+=a[i][2];
            b[i]=a[i][0];
        }
        if(sum2==0&&sum3==0){
            sort(b+1,b+n+1);
            for(int i=n;i>n/2;i--){
                ans+=b[i];
            }
            printf("%d\n",ans);
        }
        if(n==2){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(i==j)continue;
                    ans=max(ans,a[1][i]+a[2][j]);
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

