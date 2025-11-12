#include <iostream>
using namespace std;
int main(){
	int n,m,a[101],q,c,r,d,b;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			q=a[i]; 
		}
		for(int j=i-1;j>=1;j--){
			if(a[j+1]>a[j]){
				d=a[j+1];
				b=a[j];
				a[j+1]=b;
				a[j]=d;
			}			
		}
		if(i==n*m){
			for(int i=1;i<=n*m;i++){
				if(a[i]==q){
					q=i;
				}
			}
		}
	}   
	if(q%m!=0){
		c=q/m+1;
		if((q/m+1)%2==1){
			r=q%m;
		}else{
			r=n+1-q%m;
		}
	}else{
		c=q/m;
		if((q/m)%2==1){
			r=n;
		}else{
			r=1;
		}
	} 
	cout<<c<<"  "<<r;
	return 0;
}

