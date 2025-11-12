#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		sort(a,a+3);
		if(a[0]+a[1]>a[2]){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}
	
	return 0;
} 
