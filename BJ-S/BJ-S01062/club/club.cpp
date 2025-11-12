#include<bits/stdc++.h>
using namespace std;
long long _,n,a[100005][4],ji[4],xg[100005],fz[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&_);
    while(_--){
        memset(ji,0,sizeof(ji));
        long long sum=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%lld",&a[i][j]);
            }
            if(a[i][1]>=max(a[i][2],a[i][3])){
                ji[1]++;
                fz[i]=1;
                sum+=a[i][1];
            }
            else if(a[i][2]>=max(a[i][1],a[i][3])){
                fz[i]=2;
                ji[2]++;
                sum+=a[i][2];
            }
            else{
                fz[i]=3;
                ji[3]++;
                sum+=a[i][3];
            }
        }
        if(max(ji[1],max(ji[2],ji[3]))<=n/2){
            printf("%lld\n",sum);
        }
        else{
            long long top=0;
            for(int i=1;i<=n;i++){
                if(ji[1]>max(ji[2],ji[3]) && fz[i]==1){
                    xg[++top]=a[i][1]-max(a[i][2],a[i][3]);
                }
                else if(ji[2]>max(ji[1],ji[3]) && fz[i]==2){
                    xg[++top]=a[i][2]-max(a[i][1],a[i][3]);
                }
                else if(ji[3]>max(ji[1],ji[2]) && fz[i]==3){
                    xg[++top]=a[i][3]-max(a[i][2],a[i][1]);
                }
            }
            sort(xg+1,xg+top+1);
            for(int i=1;i<=max(ji[1],max(ji[2],ji[3]))-n/2;i++){
                sum-=xg[i];
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}
//100