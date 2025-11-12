#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    long long zw[15][15]={0};
    long long cj,dj=1,trcj=0,x=1;
    cin>>n>>m;
    cin>>cj;
    for(int i=1;i<=n*m-1;i++){
        cin>>trcj;
        if(trcj>cj){
            dj++;
        }
    }
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                zw[i][j]=x;
                x++;
            }
        }
        else{
            for(int i=m;i>=1;i--){
                zw[i][j]=x;
                x++;
            }
        }

    }
    for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
            if(zw[i][j]==dj){
                cout<<j<<" "<<i;
                return 0;
            }
       }
    }
    return 0;
}
