#include<bits/stdc++.h>
using namespace std;//80 bufen
const int N=1e5+10;
int f[220][111][111];
int spf[N],aid[N][4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        memset(f,0,sizeof(f));
        memset(spf,0,sizeof(spf));
        memset(aid,0,sizeof(aid));
        int n;
        scanf("%d",&n);
        bool spB=1;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&aid[i][1],&aid[i][2],&aid[i][3]);
            if(aid[i][3])spB=0;
        }
        if(spB){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=aid[i][2];
            spf[i]=aid[i][1]-=aid[i][2];
        }
        sort(spf+1,spf+1+n);
        for(int i=n;i>n/2;i--){
            sum+=spf[i];
        }
        printf("%d\n",sum);
        }
        else{
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=aid[i][3];
            for(int j=0;j<=i&&j<=n/2;j++){
                for(int k=0;k<=i-j&&k<=n/2;k++){
                    if(i-j-k>n/2)continue;
                    f[i][j][k]=f[i-1][j][k];
                    if(j-1>=0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+aid[i][1]-aid[i][3]);
                    if(k-1>=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+aid[i][2]-aid[i][3]);
                }
            }
        }int ans=0;
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n/2;j++){
                ans=max(ans,f[n][i][j]);
            }
        }
        printf("%d\n",ans+sum);}
    }
    return 0;
}
/*
t<=5
N=1e5
aij<=2e4

imput a1,a2,a3
a1-=a3,a2-=a3

a1,a2,0
f[nn][i][j]=max(
    f[nn-1][i-1][j]+a[nn][1]-a3,
    f[nn-1][i][j-1]+a[nn][2]-a3,
    f[nn-1][i][j],
)

sum+=a3
a1-=a2
sum+=a2

f[]





f[nn][i][j]/[k]\=max(
    f[nn-1][i-1][j]/[k]\+a[nn][1],
    f[nn-1][i][j-1]/[k]\+a[nn][2],
    f[nn-1][i][j]/[k-1]\+a[nn][3],
)
for(nn in 1~n){
    for(i in 0~min(nn,n/2) ){
        for(j in 0~min(nn-i,n/2)){
            k=nn-i-j;
            //dp
        }
    }
}
ans=max for(i in 0~n/2){
    for(j in 0~n/2){
        f[n][i][j]
    }    
}
4 2 1
3 2 4
5 3 4
3 5 1


*/
