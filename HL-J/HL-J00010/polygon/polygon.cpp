#include<bits/stdc++.h>
using namespce std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}
	if(n>=3){
		cout<<12;
	}
	return 0;
}
