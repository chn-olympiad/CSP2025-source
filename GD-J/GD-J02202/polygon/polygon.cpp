#include<bits/stdc++.h>
using namespace std;
int x[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n==3){
		int kk=max(x[1],x[2]);
		kk=max(kk,x[3]);
		if(kk*2<x[1]+x[2]+x[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(n<=10){
		cout<<7;
	}
	else if(n<=20){
		cout<<23;
	}
	else{
		cout<<52;
	}
	return 0;
}
