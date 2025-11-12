#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,p=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5){
		for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				if(a[i]+a[j]+a[k]>a[i]*2){
					p++;
				}
					
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				for(int z=1;z<k;z++){
					if(a[i]+a[j]+a[k]+a[z]>a[i]*2){
						p++;
					}
				}
			}
		}
	}
	cout<<p+1;
	return 0;
	}
	else if(n<=4){
		for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				if(a[i]+a[j]+a[k]>a[i]*2){
					p++;
				}
					
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				for(int z=1;z<k;z++){
					if(a[i]+a[j]+a[k]+a[z]>a[i]*2){
						p++;
					}
				}
			}
		}
	}
	cout<<p;
	return 0;
}
else{
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				if(a[i]+a[j]+a[k]>a[i]*2){
					p++;
				}
					
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				for(int z=1;z<k;z++){
					if(a[i]+a[j]+a[k]+a[z]>a[i]*2){
						p++;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				for(int z=1;z<k;z++){
					for(int d=1;d<z;d++){
						
					if(a[i]+a[j]+a[k]+a[z]+a[d]>a[i]*2){
						p++;
					}
				}
				}
			}
		}
	}
	cout<<p+1;
	return 0;
}
	return 0;
}
	
