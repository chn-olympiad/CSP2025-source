#include<bits/stdc++.h>
using namespace std;
int f(int x[5000],int y,int z){
	int n=0;
	for(int l=y;l<=z;l++){
		n+=x[l];
	}
	return n;
}
int m(int x[5000],int y,int z){
	int n=0;
	for(int l=y;l<=z;l++){
		if(x[l]>n) n=x[l];
	}
	return 2*n;
}
int main(){
	int a,b[5000],c=0,d[5000];
	cin>>a;
	for(int i=1;i<=a;i++) cin>>b[i];
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			for(int k=j+1;k<=a;k++){
				if(f(b,j,k)>m(b,j,k)){
					c++;
				} 
			}
		}
	}
	cout<<c;
	return 0;
}