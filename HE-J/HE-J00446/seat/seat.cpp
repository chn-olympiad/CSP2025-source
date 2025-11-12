#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[105];
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	int c,r;
	if(n==1&&m==1){
		c=1;
		r=1;
	}
	int max1=a[1],p=0;
	if(n<=10&&m==1){
		for(int i=2;i<=n*m;i++){
			if(a[i]>max1) p++;
		}
		if(p==0){
			c=1;
			r=1;
		}else{
			c=p+1;
			r=1;
		}
	}
	if(n==1&&m<=10){
		for(int i=2;i<=n*m;i++){
			if(a[i]>max1) p++;
		}
		if(p==0){
			c=1;
			r=1;
		}else{
			c=1;
			r=p+1;
		}
	}
	if(n<=2&&m<=2){
		for(int i=2;i<=n*m;i++){
			if(a[i]>max1) p++;
		}
		if(p==0){
			c=1;
			r=1;
		}else if(p==1){
			c=2;
			r=1;
		}else if(p==2){
			c=2;
			r=2;
		}else if(p==3){
			c=1;
			r=2;
		}
	} 
	cout<<c<<" "<<r;
	return 0;
}
