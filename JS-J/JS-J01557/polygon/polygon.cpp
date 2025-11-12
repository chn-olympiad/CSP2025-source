#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b,c;
    cin>>a>>b>>c;
    if(b>a) swap(a,b);
    if(c>a) swap(a,c);
    if(c>b) swap(b,c);
    if(b+c>a) cout<<1;
    else cout<<0;
    return 0;
}
