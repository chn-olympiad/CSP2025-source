#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,xrcj,z,max,mc,g,xrl,xrh;
    cin>>n>>m;
    z = n*m;
    int a[z+1];
    for(int i=0;i<=z;i++){
        cin>>a[i];
    }
    xrcj == a[1];
    for(int xh=1;xh<=z;xh++){
        for(int j=0;j<=z;j++){
        if(a[j]>a[j+1]){
            max == a[j];
        }else{
            max == a[j+1];
            g = a[j+1];
            a[j+1] = a[j];
            a[j] = g;
        }
    }
    }
    for(int x=0;x<=z;x++){
        if(a[x]==xrcj){
            mc == x+1;
        }
    }
    if(mc<n){
        xrl = 1;
    }else{
        xrl = mc/n;
    }
    xrh = mc%m;
    if(mc%m==0){
        xrh = m;
    }
    cout<<xrl<<" "<<xrh;
    return 0;
}
