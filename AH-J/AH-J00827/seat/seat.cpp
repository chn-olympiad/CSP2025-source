#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=110,M=20;
LL x[N],a[M][M];
bool f[M][M];
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    LL n,m,r;
    cin>>n>>m>>r;
    LL t=m*n;
    x[1]=r;
    for(LL i=2;i<=t;i++){
        cin>>x[i];
    }
    sort(x+1,x+1+t,cmp);
    for(LL i=1;i<=t;i++){
        bool fl=0;
        for(LL j=1;j<=m;j++){
            if(j%2==0){
                for(LL k=n;k>=1;k--){
                    if(!f[k][j]){
                        f[k][j]=1;
                        a[k][j]=x[i];
                        if(x[i]==r){
                            cout<<j<<" "<<k;
                            return 0;
                        }
                        fl=1;
                        break;
                    }
                }
                if(fl==1) break;
            }
            else{
                for(LL k=1;k<=n;k++){
                    if(!f[k][j]){
                        f[k][j]=1;
                        a[k][j]=x[i];
                        if(x[i]==r){
                            cout<<j<<" "<<k;
                            return 0;
                        }
                        fl=1;
                        break;
                    }
                }
                if(fl==1) break;
            }
        }
    }
    for(LL i=1;i<=m;i++){
        for(LL j=1;j<=n;j++){
            if(a[j][i]==r){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
