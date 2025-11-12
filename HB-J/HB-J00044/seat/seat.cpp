#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int rs=m*n;
    int cj[rs+10];
    for(int i=0;i<rs;i++){
        cin>>cj[i];
    }
    int rcj=cj[0],wz,c,r;
    for(int j=0;j<rs;j++){
        for(int k=0;k<rs;k++){
            if(cj[k]<cj[k+1])swap(cj[k],cj[k+1]);
        }
    }
    for(int l=1;l<=rs;l++){
        if(cj[l-1]==rcj){
            wz=l;
            break;
        }
    }
    if(wz%n==0){
        if((wz/n)%2==1)r=n;
        else r=1;
        c=wz/n;
    }
    else if(wz<=n){
        c=1;
        r=n;
    }
    else if((wz-1)%n==0){
        c=((wz-1)/n)+1;
        if(((wz-1)/n)%2==1)r=n;
        else r=1;
    }
    cout<<c<<" "<<r;

    return 0;
}
