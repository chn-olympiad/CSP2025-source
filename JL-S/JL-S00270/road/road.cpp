#include <bits/stdc++.h>
using namespace std;

int main(){
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   
   long long n,m,k,u,v,w,c,ans;
   cin>>n>>m>>k>>c;
   for(int i=0;i<=n;i++){
	   for(int j=0;j<=m;j++){
          cin>>u>>v>>w;
          w=w+u+v;
          ans=w+c;
       }
   }
   cout<<ans<<endl;
   return 0;
}
