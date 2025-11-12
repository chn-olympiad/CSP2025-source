#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s=1,c,r;
int main(){
     freopen("seat.in","r",stdin);
     freopen("seat.out","w",stdout);
     cin>>n>>m;
     for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			s++;
		}
	 }
	 if(s%m==0){
		 c=s/m;
	 }else{
         c=s/m+1;
	 }
	 cout<<c<<" ";
	 if(c%2){
		 if(s%m==0){
			 cout<<s;
		 }else{
			 cout<<s%m;
		 }
	 }else{
		 cout<<m+1-s%m;
	 }
     return 0;
}
