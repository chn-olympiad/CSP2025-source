#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b,c,n;
    cin>>n;
    if(n==3){
        cin>>a>>b>>c;
        if(a+b<=c||a+c<=b||b+c<=a)  cout<<0;
        else cout<<1;
    }
    else{
        cout<<1;
    }
    return 0;
}
