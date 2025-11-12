#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int da=-1,xm;
    int a[1000][1000];
    cin>>n>>m;
    int hang=1,l=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    xm=a[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int z=1;
            if(a[i][j]>xm&&l%2==1){
                hang++;
            }else if(a[i][j]>xm&&l%2==0){
                hang--;
            }
            if(hang>m){
                l++;
                z=1;
            }
            z++;
        }
    }
    cout<<l<<' '<<hang;
    return 0;
}
