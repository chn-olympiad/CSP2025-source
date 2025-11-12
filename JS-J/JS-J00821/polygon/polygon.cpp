#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b,c,m=0,n;
    cin>>n>>a>>b>>c;
    m=max(max(a,b),c),n=a+b+c;
    if(m*2<n) cout<<1;
    else cout<<0;
    return 0;
}
