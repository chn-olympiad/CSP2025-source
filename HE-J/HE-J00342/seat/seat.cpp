#include<bits/stdc++.h>
using namespace std;
int main(){
	int m=0,n=0,x=0,max=0,y=1,c=0,r=0;
	freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	cin>>n>>m;
for(int i=0;i<n*m;i++){
	if(i==0){
		cin>>max;
	}else{
		cin>>x;
		if(max<x){
			y++;
		}
	}
}
c=y/m;
if(c%2==0){
	r=n-y%m;
}else{
	r=y%m;
}
freopen("seat.out","w",stdout);
cout<<(c)<<' '<<(r);
return 0;
}
