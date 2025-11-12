#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int m;
	cin>>n;
	cin>>m;
	int arr[n*m];
	int a=0;
	for (int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	
	for (int j=1;j<n*m;j++){
		if(arr[j]>arr[0]){
			a++;
		}
	}
	int c;
	int r;
	c=(a/n)+1;
	if((a/n+1)%2==0){
		r=n-(a%m);
	}
	else{
		r=(a%m)+1;	
	}
	cout<<c<<" "<<r<<endl;
	
	
	return 0;
}
