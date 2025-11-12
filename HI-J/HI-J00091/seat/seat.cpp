#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,R,a,max,c=1,r=1,p=0;
	cin >>m>>n>>endl;
	R=m*n;
	for(int i=0;i<R;i++){
		cin>>a(i);
		max=a(1);
		if a(i)>max{
		   max=a(i);
		   p++;
		}
	}
	if(p==2){
		r+=1;
	}else if(p==3){
		c+=1;
		r+=1;
	}else{
		c+=3
	}
	cout<<c<<r;
	return 0;
}
