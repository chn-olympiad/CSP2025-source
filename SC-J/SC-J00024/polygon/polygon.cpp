#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+5];
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==3){
		if(a[1]+a[0]>a[2] && a[1]+a[2]>a[0] && a[0]+a[2]>a[1]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}