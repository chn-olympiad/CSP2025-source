#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a,b,c;
    cin>>n;
    if(n==1)cin>>a;
    else if(n==2)cin>>a>>b;
    else cin>>a>>b>>c;
    if(n<3){
        cout<<0;
    }
    if(n==3){
       if(max(a,max(b,c))*2<a+b+c)cout<<1;
       else cout<<0;
    }
    return 0;
}
