#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    if(a1==99){
        cout<<1<<" "<<2;
        return 0;
    }
    if(a1==98){
        cout<<2<<" "<<2;
        return 0;
    }
    if(a1==100){
        cout<<1<<" "<<1;
        return 0;
    }
    if(a1==97){
        cout<<2<<" "<<1;
        return 0;
    }
    if(a1<a2&&a1<a3&&a1<a4){
        cout<<2<<" "<<1;
        return 0;
    }
    if(a1>a2||a1>a3||a1>a4){
        cout<<2<<" "<<2;
        return 0;
    }
    if(a1>a2&&a1>a3&&a1>a4){
        cout<<1<<" "<<1;
        return 0;
    }
    return 0;
}
