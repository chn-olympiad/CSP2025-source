#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,shu=0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]*2>a[1]+a[2]){
		shu++;
	}
	if(a[1]*2>a[0]+a[2]){
		shu++;
	}
	if(a[2]*2>a[1]+a[0]){
		shu++;
	}
	cout<<shu;
	return 0;
} 
