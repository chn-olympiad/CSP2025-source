#include<bits/stdc++.h>
using namespace std;
int main(){
    int b,c,d=1,e=1,f=1,fx=1,w=0;
    cin>>b>>c;
    int a[b+1][c+1];
    for(int i=1;i<=b;i++){
        for(int j=1;j<=c;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=b;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j]>a[1][1]){
                d+=1;
            }
        }
    }
    for(int i=1;i<d;i++){
        if((f==b)and(e%2==1)){
            e+=1;
            fx=2;
        }else if((f==1)and(e%2==0)){
            e+=1;
            fx=1;
        }else{
            if(fx==1){
                f+=1;
            }else{
                f-=1;
            }
        }
    }
    cout<<e<<' '<<f;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    return 0;
}
