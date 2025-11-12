#include<bits/stdc++.h>
using namespace std; 
int n,m,k,f[1005][1005];
int mian() {
      freopen("road.in","r",stdin) ;
      freopen("road.out","w",stdout) ;
      cin >> n >> m >> k;
      for (int i=1; i<=n;i++) {
      for (int j=1;j<=n ;j++) {
      if(i==j)  f[i] [j]=1e9;
	  }
	  }
	  for (int i=1;i<=n; i++) {
	  
	  int x,y,z;
    cin>> x >> y >>z;}
	  int c=n;
	   for(int i=1; i<=k;i++) {
	   	cin >> cost[i];
	   	 for(int i=1; i<=n;i++) {
	   	 	int v;
	   	 	cin>> v;
	   	 	 for(int i=1; i<=n;i++)
	   	 	 f[++c][i]=f[i][++c]=v;
			}
	   }
	   int c= n;
   
    for(int i=1; i<=n;i++) {
     for(int j=1; j<=n;j++)	 {
     	cout << endl;
		  
	 }
	}
 for(int i=1; i<=n;i++) {
 	 for(int jj=1; j<=n;j++) {
 	 	if(i==j) contime
	  }
 }
    return 0
}
  
