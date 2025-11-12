#include<bits/stdc++.h> 
using namespace std;
int main(){
	int i,z,max,n;
	int a[1001];
	for(int i=0;i<1000;i++){
		cin>>n;
		if(n<=9) {
		a[z]=n;
		for(int j=0;j<i-1;j++){
		if(a[i]>a[j]) {
		max=a[i];
		a[i]=a[j];
		a[j]=max;
		}
		z++;
	}
		}
	}
	for(int l=0;l<z+1;l++){
		cout<<a[l];
	}
	return 0;
}
