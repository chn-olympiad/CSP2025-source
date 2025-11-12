#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
    int n,m,x;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
    	cin>>a[i];
	}
	x=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m-1;j++){
			if(a[j]<a[j+1]){
				int z=a[j];
				a[j]=a[j+1];
				a[j+1]=z;
			} 
		}
	}
	for(int i=0;i<n*m;i++){
    	if(a[i]==x){
    		x=i+1;
		}
	}
	int y;
	if(x%n==0){
		y=x/n;
		if(y%2==0){
		   cout<<y<<" "<<1;
	    }else{
	    	cout<<y<<" "<<n;
		}
	}else{
		y=x/n+1;
		if(y%2==0){
		   cout<<y<<" "<<n-x%n+1;
	    }else{
	    	cout<<y<<" "<<x%n;
		}
	}
	return 0;
}
