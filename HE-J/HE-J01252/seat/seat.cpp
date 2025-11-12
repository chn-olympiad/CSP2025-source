#include <bits/stdc++.h>
using namespace std;
float m,n,a=1e9,p=1,c=1,r=1;
int fish(float x,float y){
	int u=x/y;
	return x-(u*y);
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%f%f",&n,&m);
	for(int i=0;i<n*m;i++){
		int tmp=0;
		scanf("%d",&tmp);
		if(tmp>a){
			p++;
		}
		if(i==0) a=tmp; 
	}
	r=ceil(p/n);
	int y=fish(p,n);
	if(fish(r,2.0)!=0){
		c=y;
	}else{
		c=n-y+1;
		if(c>n){
			c=n;
		}
	}
	cout<<r<<' '<<c<<endl;
	return 0;
}
