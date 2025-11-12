#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    if(n==3){
        if(a+b<=c)cout<<0;
        else cout<<1;
    }return 0;
}
