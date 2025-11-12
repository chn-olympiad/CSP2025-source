#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m,n;
cin>>m>>n;
int a=0,b=0,a1;
cin>>a1;
int c=0,r=0;
for (int i=0;i<m*n-1;i++){
	cin>>a;
	if (a>a1){
		b++;
	}
}
if (b%n==0){
	c=b/n;
}
else{
	c=b/n+1; 
}
if (c%2==1){
	r=b-(c-1)*n;
}
else{
	r=n+1-b-(c-1)*n;
}
cout<<r<<" "<<c;
return 0;
}
