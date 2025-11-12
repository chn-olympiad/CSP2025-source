#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int jc(int q){
    int x=1;
    for(int i=1;i<=q;i++)x=x*q%998244353;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cout<<jc(n);
    return 0;
}
