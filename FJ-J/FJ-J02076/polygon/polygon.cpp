#include<iostream>
#include<cstdio>
#include<string>

using namespace std;


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int x=0;x<n-1;x++){
		for(int y=x+1;x<n;y++){
			if(a[x]<a[y]){
				a[x]=a[x]+a[y];
				a[y]=a[x]-a[y];
				a[x]=a[x]-a[y];
			}
		}
	}
	for(int x=0;x<n-2;x++){
		for(int y=x+1;x<n-1;y++){
			for(int z=y+1;z<n;z++){
				if(a[x]+a[y]+a[z]>a[z]*2){
					sum++;
				}
			}
		}
	}
	for(int k=0;k<n-3;k++){
		for(int x=0;x<n-2;x++){
			for(int y=x+1;x<n-1;y++){
				for(int z=y+1;z<n;z++){
					if(a[x]+a[y]+a[z]>a[z]*2){
						sum++;
					}
				}
			}
		}
	}
	for(int j=0;j<n-4;j++){
		for(int k=0;k<n-3;k++){
			for(int x=0;x<n-2;x++){
				for(int y=x+1;x<n-1;y++){
					for(int z=y+1;z<n;z++){
						if(a[x]+a[y]+a[z]>a[z]*2){
							sum++;
						}
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
