#include <bits/stdc++.h>
using namespace std;

int main(){
   freopen("employ.in","r",stdin);
   freopen("employ.out","w",stdout);
   
   int n,m;
   long long s;
   cin>>n>>m>>s;
   for(int i=0;i<=n;i++){
      if(s==1){
		  m=m+1;
	  }
	  else{
		  m=m+0;
	  }
      
    }
   cout<<m;
   return 0;
}
