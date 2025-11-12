#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,p=1;
int main(){
#ifndef ASTRALFLARE_CE
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
#endif
    cin>>n>>m>>r;
    for(int i=2;i<=n*m;++i){
        cin>>c;
        p+=(c>r);
    }
    cout<<(p/n+(bool)(p%n))<<" "<<((p-1)%(2*n)>=n?n-(p-1)%n:(p-1)%n+1);
}