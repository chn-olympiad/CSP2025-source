#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    cin>>a>>b>>c;
    if(a+b<=c)cout<<0;
    else cout<<1;
    return 0;
}
