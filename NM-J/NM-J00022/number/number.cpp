#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int b,c,d,e,f,g,h,j,k,l;
    int a[1000005];

    for(int i=1;i<=1;i++){
        cin>>a[i];
        if(a[i]==9){
            b=b+1;
        }
        if(a[i]==8){
            c=c+1;
        }
        if(a[i]==7){
            d=d+1;
        }
        if(a[i]==6){
            e=e+1;
        }
        if(a[i]==5){
            f=f+1;
        }
        if(a[i]==4){
            g=g+1;
        }
        if(a[i]==3){
            h=h+1;
        }
        if(a[i]==2){
            j=j+1;
        }
        if(a[i]==1){
            k=k+1;
        }
        if(a[i]==0){
            l=l+1;
        }
    }
    for(int m=1;m<=b;m++){
        cout<<"9";
    }
    for(int n=1;n<=c;n++){
        cout<<"8";
    }
    for(int o=1;o<=d;o++){
        cout<<"7";
    }
    for(int p=1;p<=e;p++){
        cout<<"6";
    }
    for(int q=1;q<=f;q++){
        cout<<"5";
    }
    for(int r=1;r<=g;r++){
        cout<<"4";
    }
    for(int s=1;s<=h;s++){
        cout<<"3";
    }
    for(int t=1;t<=j;t++){
        cout<<"2";
    }
    for(int u=1;u<=k;u++){
        cout<<"1";
    }
    for(int v=1;v<=l;v++){
        cout<<"0";
    }
    return 0;
}
