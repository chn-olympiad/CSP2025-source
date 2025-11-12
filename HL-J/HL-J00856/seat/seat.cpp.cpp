#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

long long n,m,a[1000][1000],zwh=0,zwhi=0,zwhj=0;
int main(){
    freopen("seat.in",'r',stdin);
    freopen("seat.out",'w',stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        else{
            for(int j=m;j>=1;j--){
                cin>>a[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                if(a[1][1]<=a[i][j]){
                    zwh++;
                }
            }
        }
        else{
            for(int j=m;j>=1;j--){
                if(a[1][1]<=a[i][j]){
                    zwh++;
                }
            }
        }
    }
    zwhi=zwh/n+1;
    zwhj=zwh%n+1;
    cout<<zwhj<<' '<<zwhi;
    return 0;
}
