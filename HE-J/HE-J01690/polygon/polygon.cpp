#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int b[10000000];
int main(){
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	long long fangan=0;
	int x=1,y=2,z=3;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//对于三角形进行判断 
	for(int i=0;i<n;i++){
		x++;
		if(a[x]+a[y]>a[z]&&a[x]+a[z]>a[y]&&a[z]+a[y]>a[x]){
					fangan++;
					
				}
		
		
		for(int j=0;j<n;j++){
			y++;
			if(a[x]+a[y]>a[z]&&a[x]+a[z]>a[y]&&a[z]+a[y]>a[x]){
					fangan++;
					
				}
				
				
			for(int k=0;k<n;k++){
				z++;
				if(a[x]+a[y]>a[z]&&a[x]+a[z]>a[y]&&a[z]+a[y]>a[x]){
					fangan++;
					
					
				}
			}
		}
	}
	//对于多边形进行重复判断 
	for(int i=0;i<=n;i++){
		int m=1;
		for(int j;j<=i;j++){
			if(a[m]+a[m+j]!=b[i]){
				fangan++;
				b[i]=a[m]+a[m+j];
			}else{
				fangan--;
			}
		}
	}
	cout<<fangan;
	return 0;
}
