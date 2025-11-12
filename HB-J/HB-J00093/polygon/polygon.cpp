#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
   int n,m,mm,mi=INT_MAX;
   cin>>n;
   for(int i=1;i<=n;i++){
        cin>>m;
        m+=min(m,mi);
        mi=m;
        mm=m%998244353;
        }
   cout<<mm;
    return 0;
}

