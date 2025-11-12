#include <bits/stdc++.h> 
using namespace std;
int mmm,nnn;
int b[110],hip;
int fin(int x,int y,int f){
	
	int l,r,mid,jjj;
	
	l=x;r=y;mid=(l+r)/2;
	if(b[mid]==f){
	return mid+1;
	}else if(b[mid]>f){
		r=mid;
		cout<<" "<<l<<" "<<r<<" "<<mid<<endl;
			return fin(l,r,f);
	}else if(b[mid]<f) {
	l=mid+1;
	cout<<l<<" "<<r<<" "<<mid<<endl;
	return fin(l,r,f);
	}
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>mmm>>nnn;
	
	int a[mmm+10][nnn+10];
	

   for(int i=0;i<mmm*nnn;i++) {
   	cin>>b[i] ;
   }
   int hi=b[0],hip;
    sort(b,b+mmm*nnn);
    int place=fin(0,mmm*nnn,hi);
   int con=1;
   int out; 
    for(int a=place;a>=mmm;a=a-mmm){
	con++;
	out=a-mmm;
}
	if(con%2==1){
    	cout<<con<<out;//con
	}else{
		cout<<con<<" "<<mmm-out; 
	}
   return 0;
}
