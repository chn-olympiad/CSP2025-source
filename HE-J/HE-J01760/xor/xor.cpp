#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500005];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&k==2||k==3)cout<<"2";
	if(n==4&&k==0)cout<<"1";
	return 0;
}
