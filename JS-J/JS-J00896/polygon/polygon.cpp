#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,MOD=998244353;
int a[N],f[2*N][4];//f[i][j]max>i,2j>i,have 0,1,2,3,ff_state
int n,res,maxa;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        maxa=max(a[i],maxa);
    }
    sort(a+1,a+1+n);
    res=1;
    for(int i=1;i<=n;i++){
        res=res*2%MOD;
    }
    f[0][0]=1;
    res=(res-1-n-n*(n-1)/2+MOD)%MOD;
    //printf("%d\n",res);
    for(int i=1;i<=n;i++){
        for(int j=(2*maxa)-a[i];j>=0;j--){
            for(int k=min(3,i);k>=0;k--)if(f[j][k]>0){
                int tmp=f[j][k];
                if(k==3||k==2){
                    f[j+a[i]][3]=(tmp+f[j+a[i]][3])%MOD;
                    if(j+a[i]<=a[i]*2){
                        res=(res-tmp+MOD)%MOD;
                        //cout<<f[i-1][j][k]<<i<<j+a[i]<<k+1<<endl;
                    }
                }else {
                    f[j+a[i]][k+1]=(tmp+f[j+a[i]][k+1])%MOD;
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
