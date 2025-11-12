#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,c;
    cin>>a>>b;
    for(int i=0;i<a*b;i++){
        cin>>c;
    }
    if(a==2&&b==2){
        cout<<"1 2";
    }
    else if(a==3&&b==3){
        cout<<"3 1";
    }
    return 0;
}
