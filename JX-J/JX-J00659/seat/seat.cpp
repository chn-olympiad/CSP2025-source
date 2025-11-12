#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   int n,m;
   cin>>n>>m;
   int c=n*m;a[n+5][m+5],b[c+5],d=0;
   for(int i=1;i<=c;i++){
	   cin>>b[i];
	   d+=1;
   }
   int e=b[1],f;
   sort(b,b+d-1);
   for(int i=1;i<=d-1;i++){
	   if(b[i]==e){
		   f=i;
	   }
   }
   int han,lie;
   if(f<=n){
	   lie=1;
	   han=f;
   }else{
	   if(f%n==0){
		   lie=f/n;
		   if(lie%2==0){
			   han=1;
			}else{
				han=n;
		    }
	   }else{
		   lie=f/n+1;  
		   if(lie%2==0){
			   han=n-f%n;
			}else{
				han=f%n;
		    }
		}
   }
   cout<<lie<<" "<<han;
   fclose(stdin);
   fclose(stdout);
   return 0;
}
   
