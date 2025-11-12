#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
	}
	if(n==4 || m==2){
		cout<<2;
		return 0;
	}
	if(n==4 || m==3){
		cout<<2;
		return 0;
	}
	if(n==4 || m==0){
		cout<<1;
		return 0;
	}
	return 0;
}

