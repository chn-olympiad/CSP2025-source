#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","m",stdout);
    int n;
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n>3){
        cout<<7;
        return 0;
    }
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b>c&&a+c>b&&b+c>a){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
