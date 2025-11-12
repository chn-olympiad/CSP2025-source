#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int a[4]={2,3,4,1};
	int s;
	for(int i=0;i<=3;i++){
		if(a[i]<a[i+1]){
			if(i<3){
				s=a[i+1];
				a[i+1]=a[i];
				a[i]=s;
				if(i==2) break;
			}
			if(i==3){
				if(a[0]<a[1]){
					s=a[1];
					a[1]=a[0];
					a[0]=s;
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<a[i]<<" ";
	}
	
}
