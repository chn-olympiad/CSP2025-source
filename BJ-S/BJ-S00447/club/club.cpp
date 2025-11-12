#include<bits/stdc++.h>
using namespace std;
long long n,t,a[1000005],b[1000005],yi[100005],minj,minx,numa,numb,numc,c[1000005],dp[1000005],sum;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int guang=1;guang<=t;guang++){
        cin>>n;
        numa=0;
        numb=0;
        numc=0;
        for(int i=1;i<=n;i++){
            yi[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=1;i<=n;i++){
            minx=100000005;
            dp[i]=dp[i-1]+max(a[i],max(b[i],c[i]));
            if(a[i]>=b[i]&&a[i]>=c[i]){
                numa++;
            }
            else if(b[i]>a[i]&&b[i]>=c[i]){
                numb++;
            }
            else if(b[i]<c[i]&&a[i]<c[i]){
                numc++;
            }
            if(numa>n/2){
                for(int j=1;j<=i;j++){
                    if((a[j]-max(b[j],c[j]))<minx&&yi[j]!=1){
                        minx=a[j]-max(b[j],c[j]);
                        minj=j;
                   }
                }
                dp[i]-=minx;
                yi[minj]=1;
                if(b[minj]>=c[minj]){
                    numb++;
                }else{
                    numc++;
                }
                numa--;
                continue;
            }
            if(numb>n/2){
                for(int j=1;j<=i;j++){
                    if((b[j]-max(a[j],c[j]))<minx&&yi[j]!=1){
                        minx=b[j]-max(a[j],c[j]);
                        minj=j;
                   }
                }
                dp[i]-=minx;
                yi[minj]=1;
                if(a[minj]>=c[minj]){
                    numa++;
                }else{
                    numc++;
                }
                numb--;
                continue;
            }
            if(numc>n/2){
                for(int j=1;j<=i;j++){
                    if((c[j]-max(b[j],a[j]))<minx&&yi[j]!=1){
                        minx=c[j]-max(a[j],b[j]);
                        minj=j;
                   }
                }
                dp[i]-=minx;
                yi[minj]=1;
                if(a[minj]>=b[minj]){
                    numa++;
                }else{
                    numb++;
                }
                numc--;
                continue;
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
