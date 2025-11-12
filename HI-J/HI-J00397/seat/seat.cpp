#include<bits/stdc++.h>
using namespace std;
struct math{
	int A,B;
}a[1000005];
bool ab(math x,math y){
	return x.A>y.A;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
   int n,m,z;
   cin>>n>>m; 
   for(int c=1;c<=n*m;c++){
   	  cin>>a[c].A;
   	  a[c].B=c;  
   } 
   sort(a+1,a+1+n*m,ab);
   for(int c=1;c<=n*m;c++){
   	if(a[c].B==1){
   		z=c;
   		break;
	   }
   }
   int l=z/n;
   z=z%n;
   
   if(l%2==0){
   	if(z==0) z=1;
	else l++; 
   	cout<<l<<" "<<z;
   }
   else{
   	if(z==0) z=n;
	else{
	  l++; 
	  z=m-z+1;	
	} 
   	cout<<l<<" "<<z;
   } 
	return 0;
} 
