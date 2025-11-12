#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,m,k,i,vi,ji,wi,j;
cin>>n>>m>>k;
for(i>=1;i<=m;i++){
    cin>>vi>>ji>>wi;
    cout<<(vi+ji+wi)*n/3;
}

return 0;
}
