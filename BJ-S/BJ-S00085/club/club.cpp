#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int t,n,a[maxn][4],q[maxn];
int p[maxn],cnt=0;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
            }
        }
        long long res=0;
        int sum1=0,sum2=0,sum3=0;
        for(int i=1;i<=n;i++){
            if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) q[i]=1,res+=a[i][1],sum1++;
            else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]) q[i]=2,res+=a[i][2],sum2++;
            else if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]) q[i]=3,res+=a[i][3],sum3++;
        }
        if(sum1>n/2){
            for(int i=1;i<=n;i++){
                if(q[i]==1) p[++cnt]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
            }
            sort(p+1,p+1+cnt);
            for(int i=1;i<=sum1-n/2;i++) res-=p[i];
        }
        else if(sum2>n/2){
            for(int i=1;i<=n;i++){
                if(q[i]==2) p[++cnt]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
            }
            sort(p+1,p+1+cnt);
            for(int i=1;i<=sum2-n/2;i++) res-=p[i];
        }
        else if(sum3>n/2){
            for(int i=1;i<=n;i++){
                if(q[i]==3) p[++cnt]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
            }
            sort(p+1,p+1+cnt);
            for(int i=1;i<=sum3-n/2;i++) res-=p[i];
        }
        printf("%lld\n",res);
    }
    return 0;
}
