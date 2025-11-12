#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,c=1,d=1,f=0,e=0;
int h[10001];
cin>>n>>m;
for(int i=0;i<m*n;i++){
cin>>h[i];	
}
for(int i=0;i<m*n;i++){
	if(h[0]<h[i]){
		f++;
	}
}
while(f--){
	d++;
if(d>n){
	c++;d=n;
while(1){
	if(d<n){
	d=1;break;
	}
	d--;
}
}

	
}


cout<<c<<" "<<d;


return 0;
}

