#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[115],b[115][115],c[115],x=0,d[2];
    cin >> n >> m;
    x=n*m;
    for(int i=0;i<x;i++){
        cin >> a[i];
    }
    d[0]=a[0];
   for(int j=0;j<=x;j++){
		for(int i=1;i<x;i++){
	        if(a[i]>a[i-1]){
	        	c[i]=a[i];
	            a[i]=a[i-1];
	            a[i-1]=c[i];
        	}
    }
}
	if(x%2==0){
		for(int j=0;j<=x/n;j++){
			for(int i=0;i<=n;i++){
				b[0][i]=a[i];
				if(d[0]==b[j][i]){
						cout << j << " "<< i <<" ";
						}
				}
			for(int i=n;i>=1;i--){
				b[1][i]=a[i];
				if(d[0]==b[j][i]){
					cout << j << " "<< i <<" ";
						}
				}
	}
}
	else{
		for(int j=0;j<=x/n;j++){
			for(int i=0;i<=n;i++){
				b[0][i]=a[i];
				if(d[0]==b[j][i]){
					cout << j << " "<< i <<" ";
						}
				}
			for(int i=n;i>=1;i--){
				b[1][i]=a[i];
				if(d[0]==b[j][i]){
					cout << j << " "<< i <<" ";
						}
				}
		}
		for(int j=0;j<=x/n;j++){
			for(int i=0;i<=n;i++){
				b[0][i]=a[i];
				if(d[0]==b[j][i]){
					cout << j << " "<< i <<" ";
						}
		}
	}
}
    return 0;
}
