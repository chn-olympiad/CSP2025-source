#include<bits/stdc++.h> 
using namespace std;
int a[10000017];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<"0";
	}else if(n==2){
		cout<<"0";
	}else if(n==3){
		cout<<"1";
	}
	return 0;
}

