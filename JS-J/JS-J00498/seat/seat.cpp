#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int n,m;
bool ma(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]>a[1][1]){
                return false;
            }
        }
    }
    return true;
}
void chu(){
    int mx=0,my=0,mm=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]>mm){
                mm=a[i][j];
                mx=i;
                my=j;
            }
        }
    }
    a[mx][my]=0;
    return;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                if(ma()){
                    cout<<i<<" "<<j;
                    return 0;
                }
                chu();
            }
        }
        else{
            for(int j=m;j>=1;j--){
                if(ma()){
                    cout<<i<<" "<<j;
                    return 0;
                }
                chu();
            }
        }
    }
    return 0;
}
