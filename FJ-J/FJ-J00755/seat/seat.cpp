#include<bits/stdc++.h>
using namespace std;
int n,m,a[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		a[i]=-a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
	   if(a[i]==k){
	   	  int c=(i+n-1)/n,r=0;
	   	  if(c%2==1){
	   	  	 r=i%n;
	   	  	 if(r==0){r=n;}
	   	  }
	   	  else{
	   	  	 r=n-i%n+1;
	   	  	 if(i%n==0){r=1;}
	   	  }
	   	  printf("%d %d",c,r);
		  break;
	   }	
	}
	return 0;
}
