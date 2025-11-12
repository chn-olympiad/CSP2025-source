#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    if(2*max(x,max(y,z))<x+y+z)cout<<1;
    else cout<<0;
    return 0;
}
