#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int b[n*m]={0};
	for(int i=0;i<m*n;i++){
		cin>>b[i];
	}
	int key=b[0];
	for(int i=1;i<m*n;i++){
		for(int j=0;j<m*n-i;j++){
			if(b[j]<b[j+1]){
				swap(b[j],b[j+1]);
			}
		}
	}
	for(int i=0;i<m*n;i++){
		if(b[i]==key){
			key=i+1;
			break;
		}
	}
	int x,y;
	if(key%n==0){
		x=key/n;
		if(x%2==0){
			y=1;
		}
		else{
			y=n;
		}
	}
	else{
		x=key/n+1;
		if(x%2==0){
			y=n-(key%n)+1;
		}
		else{
			y=key%n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
