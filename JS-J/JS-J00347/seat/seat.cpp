#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000],r,c;
int  cmp(int x,int y){
    return y<x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    int z=a[1];
    sort(a+1,a+1+n*m,cmp);

    for(int i=1;i<=n*m;i++){
        if(z==a[i]){
            z=i;
            break;
        }
    }
    int y=z%n;
    c=int(z*1.0/n+0.9);
    if(c%2==1){
        if(y==0){
            r=m;
        }else{
            r=y;
        }
    }else{
        if(y==0){
            r=1;
        }else{
            r=m-y+1;
        }
    }
    cout<<c<<' '<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
