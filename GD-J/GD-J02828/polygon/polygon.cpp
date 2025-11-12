#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,max=0;
	cin>>n;
	int a[5005]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(max<a[i]){
			max=a[i];
		}
	}
	return 0;
}
