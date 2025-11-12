#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   int n,m,k,conna[1000005],connb[1000005],v[1000005],chan[15],conv[15][1000005];
   cin>>n>>m>>k;
   for(int i=0;i<m;i++){
       cin>>conna[i]>>connb[i]>>v[i];
   }
   for(int i=0;i<k;i++){
       cin>>chan[i];
       for(int j=0;j<m;j++){
           cin>>conv[i][j];
   }
}
return 0;
}
