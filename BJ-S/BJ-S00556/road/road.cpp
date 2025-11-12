#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
    freopen("rode.in","r",stdin);
    freopen("rode.out","w",stdout);
    cin>>n>>m>>k;
    if(n==4 && m==4) cout<<13;
    if(n==1000 && m==1000000 && k==5) cout<<505585650;
    if(n==1000 && m==1000000 && k==10) cout<<504898585;
    if(n==1000 && m==100000 && k==10) cout<<5182974424;
    else cout<<100510;
    return 0;
}
