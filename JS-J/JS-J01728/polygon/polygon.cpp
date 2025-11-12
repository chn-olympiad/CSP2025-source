#include<bits/stdc++.h>
using namespace std;
int main(){
     freopen("polygon.in","r",stdin);
     freopen("polygon.out","w",stdout);
     ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     int n;
     cin>>n;
     int b[n];
     for(int i=0;i<n;i++){
		 cin>>b[i];
	 }
     if(n<3){
		 cout<<0;
		 return 0;
	 }
	 if(n==3){
		 int x=b[0]+b[1]+b[2];
		 int y=max(b[0],b[1]);
		 y=max(y,b[2]);
		 y=y*2;
		 if(x>y){
			 cout<<1;
		 }else{
			 cout<<0;
		 }
		 return 0;
	 }
     return 0;                       
}
