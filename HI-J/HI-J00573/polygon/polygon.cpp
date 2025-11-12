#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	int y,x=0,yy=0,sum=0;
	cin>>y;
	for(int i=1;i<=y;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=y;i++){
		yy=a[i];
		x=max(x,a[i]);
		for(int j=i+1;i<=y;i++){
			x=max(x,a[j]);
			yy+=a[j];
			if(yy>=2*x){
				sum+=1;
			}else{
				while true{
					for(int j=i+1;i<=y;i++){
						x=max(x,a[j]);
						yy+=a[j];
						if(yy>=2*x){
							sum+=1;
						}
					}
				}
			}	
		}
		x=0;
	}
	cout<<sum;
	return 0;
} 

