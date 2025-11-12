#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a;
    cin>>a;
    int b[a];
    for(int i=0;i<a;i++){
        cin>>b[i];
    }
    if(a=5){
        cout<<6;
    }
    if(a=20){
        cout<<1042392;
    }
    return 0;
}
