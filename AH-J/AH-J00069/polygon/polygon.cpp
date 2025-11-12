#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
long long a[MAXN],n,big=-1,k=1,h=1,sum=0;
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
	   big=max(big,a[i]);
   }
   big*=2;
   sort(a+0,a+n);
   while(1){
	     for(int i=h;i<=n;i++){
			  if(big<0) break;
		      if(k==i) continue;
	          big-=a[i];
          }
          if(big<0)  sum++;
       if(k==n){
		  h++;
		  k=h;
	   }else{
		  k++;
	   }
	   if(h==n){
		  cout<<sum;
		  return 0;
	   }
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}
