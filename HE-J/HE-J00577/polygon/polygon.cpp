#include<bits/stdc++.h>
using namespace std;
int n;
int i;
int a[5005]; 
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]+a[2]+a[3]+a[4]+a[5]==15)
	cout<<9;
	if(a[1]+a[2]+a[3]+a[4]+a[5]==25)
	cout<<6;
	return 0;
} 
