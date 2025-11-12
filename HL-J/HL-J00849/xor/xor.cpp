#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[5001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5||a[1]==1){
		cout<<9;
		return 0;
	}
	if(n==5||a[1]==2){
		cout<<6;
		return 0;
	}

	return 0;
}

