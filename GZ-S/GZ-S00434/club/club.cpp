//GZ-S00434 邓彬豪 遵义市南白中学 
#include<bits/stdc++.h>
using namespace std;
int h(int x,int a,int c,int b){
	if(x==a){
	c++;
	b++;
}
}
int main(){
	int n,t,d=0,e=0,sum=0,A=0,B=0,C=0,x=0,y=0,z=0,q;
	int a[n][n];
	int b[n][n];
	int c[n][n];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][i]>>b[i][i]>>c[i][i];
	}
	i=1;
	while(n--){
		if(a[i][i]<a[i+1][i+1]){
			a[0][i]=a[i+1][i+1];
			a[0][i+1]=a[i][i];
		}
		if(c[i][i]<c[i+1][i+1]){
			c[0][i]=c[i+1][i+1];
			c[0][i+1]=c[i][i];
		}
		if(b[i][i]<b[i+1][i+1]){
			b[0][i]=b[i+1][i+1];
			b[0][i+1]=b[i][i];
		}
    }
    for(int i=1;i<=n;i++){
    	x=a[0][i]+a[0][i+1];
    	y=a[0][i]+b[0][i];
    	z=a[0][i]+c[0][i];
    	q=b[0][i]+c[0][i];
    	d=max(x,y);
    	sum=max(z,q);
    	e=max(sum,d);
    	h(e,x,A,A);
    	h(e,y,A,B);
    	h(e,z,A,C);
    	
	}
}
}
