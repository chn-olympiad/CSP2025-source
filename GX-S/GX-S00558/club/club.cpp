#include<bits/stdc++.h>
using namespace std;
int T,n,A,B,C;
int a[1000001],dp[1000001],b[1000001],c[1000001],sum[1000001],ma;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            sum[i]=max(a[i],max(b[i],c[i]));
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(sum[j]>sum[i]){
                    swap(sum[i],sum[j]);
                    swap(a[i],a[j]);
                    swap(b[i],b[j]);
                    swap(c[i],c[j]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(A==n/2){
                a[i]=0;
            }
            if(B==n/2){
                b[i]=0;
            }
            if(C==n/2){
                c[i]=0;
            }
            dp[i]=dp[i-1]+max(a[i],max(b[i],c[i]));
            if(a[i]>b[i]&&a[i]>c[i]){
                A+=1;
            }else if(b[i]>a[i]&&b[i]>c[i]){
                B+=1;
            }else if(c[i]>b[i]&&c[i]>a[i]){
                C+=1;
            }
        }
        cout<<dp[n]<<endl;
        for(int i=1;i<=n;i++){
            dp[i]=0;
            A=0;
            B=0;
            C=0;
        }
    }
    return 0;
}
