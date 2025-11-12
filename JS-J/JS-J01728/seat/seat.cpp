#include<bits/stdc++.h>
using namespace std;
int x[101];
int main(){
     freopen("seat.in","r",stdin);
     freopen("seat.out","w",stdout);
     ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     long long m,n;
     cin>>m>>n;
     for(int i=1;i<=m*n;i++){
			 cin>>x[i];
	 }
	 long long a,b=0;
	 a=x[1];
	 for(int i=1;i<=m*n;i++){
		 for(int j=1;j<=i;j++){
			 if(x[j]<x[i]){
				 swap(x[j],x[i]);
			 }
			 if(x[i]==a){
     			 b=i;
			 }
		 }
	 }
	 long long c=b/m,d=b%m;
	 if(d==0){
		 cout<<c<<' ';
	 }else{
		 cout<<c+1<<' ';
		 c=c+1;
	 }
	 if(d==0){
		 d=m;
	 }
	 if(c%2==1){
		 cout<<d;
	 }else{
		 cout<<m-d+1;
	 }
     return 0;                       
}
