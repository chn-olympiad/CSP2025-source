#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,n1,n2,n3;
    cin>>n>>n1>>n2>>n3;
    if(n1+n2+n3> 2*(max(max(n1,n2),max(n2,n3)))) cout<<1;
    else cout<<0;



    return 0;
}
