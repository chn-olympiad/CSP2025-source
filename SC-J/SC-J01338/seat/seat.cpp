#include<bits/stdc++.h>
using namespace std;
int main(){
 freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
int a[1000],n,m,paiming,c,r;
cin>>n>>m;
for(int i=1;i<=n*m;i++)
 cin>>a[i];
  int R=a[1];
  sort(a+1,a+n*m+1);
  for(int i=1;i<=n*m;i++){
  	if(a[i]==R) paiming=n*m-i+1;
  }
  
   for(int N=1;N<=n;N++){
   	if(paiming/n<N){
	   c=N;
	   break;}
	if(paiming%n==0){
	   c=paiming/n;
	   break;}
   }
      int b=paiming%n;
      if(b==0&&c%2==0) r=1;
    if(b==0&&c%2!=0) r=n;
     if(c%2==0&&b!=0) r=n-b+1;
     if(c%2!=0&&b!=0) r=b;
     cout<<c<<" "<<r;
     return 0;
}