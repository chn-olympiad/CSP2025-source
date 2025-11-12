#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long t,n,a1[100005],a2[100005],d[205][105][105],a3[100005],ans;
void slv(){
    ans=0;
    sort(a1+1,a1+1+n);
    for(int i=n;i>n/2;i--){
        ans+=a1[i];
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);ans=0;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a1[i],&a2[i],&a3[i]);
        }
        if(n>300){
            slv();
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2;k++){
                    if(j+k>i||i-(j+k)>n/2) continue;
                    if(j>0) d[i][j][k]=max(d[i][j][k],d[i-1][j-1][k]+a1[i]);
                    if(k>0) d[i][j][k]=max(d[i][j][k],d[i-1][j][k-1]+a2[i]);
                    if(j+k<i) d[i][j][k]=max(d[i][j][k],d[i-1][j][k]+a3[i]);
                    ans=max(ans,d[i][j][k]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2;k++){
                    //cout<<d[1][j][k]<<" ";
                    d[i][j][k]=0;
                }
                //cout<<"\n";
            }
            //cout<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
