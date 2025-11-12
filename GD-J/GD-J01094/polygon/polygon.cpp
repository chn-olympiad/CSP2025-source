#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[10000*5+3];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int z=j+1;z<=n;z++){
				if(i+j+z>max(i,max(j,z))){
					sum++;
				}
			} 
		}
	} 
	for(int i=1;i<=n-3;i++){
		for(int j=i+1;j<=n-2;j++){
			for(int z=j+1;z<=n-1;z++){
				for(int x=z+1;x<=n;x++){
				
				if(i+j+z+x>max(max(i,x),max(j,z))){
					sum++;
				}}
			} 
		}
	} 
	for(int i=1;i<=n-4;i++){
		for(int j=i+1;j<=n-3;j++){
			for(int z=j+1;z<=n-2;z++){
				for(int x=z+1;x<=n-1;z++)
					for(int y=x+1;y<=n;y++){
					
				if(i+j+z+x+y>max(y,max(max(i,x),max(j,z)))){
					sum++;
				}}
			} 
		}
	} 
	cout<<sum;
	return 0;
}
