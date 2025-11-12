#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int gz(int a,int b){
    if(a>b){
        return a>b;
    }
    else{
        return b>a;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    int x,y,wz,ix,iy;
    cin>>x>>y;
    int xy=x*y;
    int a[xy];
    int b[x][y];
    for(int i=0;i<xy;i++){
        cin>>a[i];
    }

    wz=a[0];
    sort(a,a+xy,gz);

    for(int i=0;i<x;i++){
        if(x%2==0){
            for(int j=y;j>=0;j--){
                b[i][j]=a[i];
            }
        }
        if(x%2==1){
            for(int j=0;j<y;j++){
                b[i][j]=a[i];
            }
        }
    }

    for(int i = 0;i<x;i++){
        for(int j = 0;j<y;j++){
            //cout<<b[i][j]<<" ";
            if(b[i][j]==wz){
                cout<<i<<j;
            }
        }
    }
    return 0;
}
