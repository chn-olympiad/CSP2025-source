#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],f[15][15],n1=1,m1=1,sn,sm,b;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            b=a[i];
        }
    }
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[j]<a[j+1]){
                int c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
    }
    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(m1%2!=0){
                f[n1][m1]=num;
                num++;
                if(n1==n){
                    m1++;
                }else{
                    n1++;
                }
            }
            else{
                f[n1][m1]=num;
                num++;
                if(n1==1){
                    m1++;
                }else{
                    n1--;
                }
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==b){
            sm=i;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(f[i][j]==sm){
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}
