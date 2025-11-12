#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   int n, m, K;
   cin>>n>>m>>K;
   int u[m][3],c[K],a[K][n];
   for(int i=1;i<=m;i++){			
   	cin>>u[i-1][0];
   	cin>>u[i-1][1];
   	cin>>u[i-1][2];
   }
   for(int i=1;i<=K;i++){			
   	cin>>c[i-1];
   	for(int b=1;b<=n;b++){			
   	cin>>a[i-1][b-1];
   }
   }
   
   fclose stdin;fclose stdout;
   return 0;
}
