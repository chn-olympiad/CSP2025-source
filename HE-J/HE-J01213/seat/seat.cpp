#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	int a[100] = {};
	int b[100] = {};
	int sum = m*n;

	for(int i = 0;i<sum;i++){
		cin>>a[i];
	}
	for(int i = 0;i<sum;i++){
		if(a[i]<=a[i+1]){
			swap(a[i],a[i+1]);
		}
		cout<<a[i];
	}
	for(int i = 0;i<m;i++){
		for(int j = 0;i<n;j++){
			if(a[j]>=a[j+1]){
				swap(a[j],a[j+1]);	
			}
			else{
				b[i] = a[i];
			}
		}cout<<a[i];
	}
	 
	
	
	
}

