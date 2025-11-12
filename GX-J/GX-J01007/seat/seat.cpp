#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[11][11];
int b[11][11];
int ma=-100,ll,rr,kk;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    kk=a[1][1];
    for(int k=1;k<=n;k++){
        if(k%2==1){
            for(int l=1;l<=m;l++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(a[i][j]>ma){
                            ma=a[i][j];
                            ll=i;
                            rr=j;
                        }
                    }
                }
                a[ll][rr]=0;
                b[k][l]=ma;
                if(b[k][l]==kk){
                    cout<<k<<" "<<l;
                    return 0;
                }
                ma=-100;
            }
        }else{
            for(int l=m;l>=1;l--){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(a[i][j]>ma){
                            ma=a[i][j];
                            ll=i;
                            rr=j;
                        }
                    }
                }
                a[ll][rr]=0;
                b[k][l]=ma;
                if(b[k][l]==kk){
                    cout<<k<<" "<<l;
                    return 0;
                }
                ma=-100;
            }

        }
    }
    return 0;
}
