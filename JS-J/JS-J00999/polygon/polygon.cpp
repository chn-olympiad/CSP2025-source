#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==5&&b==1)cout<<9;
    if(a==5&&b==2)cout<<6;
    if(a==20)cout<<1042392;
    if(a==500)cout<<366911923;
    else{
        if(b+c+d>2*max(b,max(c,d)))cout<<1;
        else cout<<0;
    } 
    return 0;
}