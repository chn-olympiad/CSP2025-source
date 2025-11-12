#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL a[110];
LL b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n*m;i++){
        cin>>a[i];
    }
    LL xx=a[1];
    sort(a+1,a+1+n*m);
    LL k=n*m;
    for(LL y=1;y<=m;y++){
        if(y%2==1){
            for(LL x=1;x<=n;x++){
                b[x][y]=a[k];
                k--;
            }
        }else{
            for(LL x=n;x>=1;x--){
                b[x][y]=a[k];
                k--;
            }
        }
    }
    for(LL i=1;i<=n;i++){
        for(LL j=1;j<=m;j++){
            if(b[i][j]==xx){
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
