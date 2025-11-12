#include<bits/stdc++.h>
using namespace std;
int n,a[100009],m,p,sum,c[100000],num;
int b[100009]={},xz=0;
void e(int q,int w){
	if((q+w-1)<n){
		for(int i=w;i<n;i++){
	    	if(b[i]==0){
		    	b[i]=1;
		    	num++;
		    	c[i]=a[i];
		    	if(num==q){
			    	for(int j=0;j<=i;j++){
			     		xz=xz+c[j];
			    	}
			    	if(c[i]*2<xz){
			     		sum++;
			    	}
		    	}
		    	else{
			    	e(q,i+1);
		    	}
		    	b[i]=0;
		    	num--;		
	    	}
	    }
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		p=a[i];
		for(int j=0;j<i;j++){
			if(a[i]<a[j]){
				for(int k=i;k>=j;k--){
					a[k]=a[k-1];
				}
				a[j]=p;
			}
		}
	}
	int max=a[n-1];
	for(int i=3;i<=n;i++){
		e(i,0);
	}
	cout<<(sum%998244353);
	return 0;
}
