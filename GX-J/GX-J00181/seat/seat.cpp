#include <bits/stdc++.h>
using namespace std;
int f[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,z,h,p,xa=1,xb=1,bb=1;
    cin>>a>>b>>z;
    p=a*b;
    for(int i=1;i<=a*b-1;i++){
        cin>>h;
        f[h]++;
    }

    for(int i=1;i<=100;i++){
        if(f[i]==1&&i<z){
            p--;
        }
    }
    for(int i=1;i<=p-1;i++){
        if(xb%2==1&&xa+1<=a&&bb==1){
            xa++;
            bb--;
        }
        if(xa+1>a&&xb%2==1&&bb==1&&xb<b){
            xb++;
            bb--;
        }
        if(xb%2==0&&xa-1>=1&&bb==1){
            xa--;
            bb--;
        }
        if(xa-1<1&&xb%2==0&&bb==1&&xb<b){
            xb++;
            bb--;
        }
        bb=1;
    }
cout<<xb<<" "<<xa;
return 0;
}

