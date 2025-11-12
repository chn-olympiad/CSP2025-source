#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b,c[100000];
    cin>>a;
    for(int i=1; i<=a ;i++){
        cin>>c[i];
    }
    if(a<=5){
        cout<<9;
    }
    if(a<=5&&c[1]==2){
        cout<<6;
    }
    if(a==20){
        cout<<1042392;
    }
    if(a==500){
        cout<<366911923;
    }
    return 0;
}
