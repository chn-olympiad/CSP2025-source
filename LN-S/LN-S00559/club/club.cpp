#include<bits/stdc++.h>
using namespace std;
const int mxn=1e5+5;
long long t,n,a[mxn][3],ansa[mxn],ansb[mxn],cnt[mxn],w,p;
int main(){
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%lld",&a[i][j]);
                ansa[i]=max(ansa[i],a[i][j]);
                if(a[i][j]==ansa[i]){
                    swap(a[i][3],a[i][j]);
                }
                if(a[i][1]>a[i][2]){
                    swap(a[i][1],a[i][2]);
                }
                if(a[i][j]==ansa[i] and ansa[i-1]==a[i-1][j]){
                    cnt[j]++;
                }
            }
            if(cnt[i]<=n/2){
                w+=ansa[i];
            }
            else{
                w+=max(ansa[i]+a[i-1][2],ansa[i-1]+a[i][2]);
            }
            ansa[i]=0,cnt[i]=0;
        }
       printf("%lld\n",w);
        w=0;
    }
    return 0;
}
