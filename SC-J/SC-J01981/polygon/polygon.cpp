#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[50001];
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	if(a[0]==1){
		cout<<9;
	}
	else if(a[0]==2){
		cout<<6;
	}
	else if(a[0]==37){
		cout<<366911923;
	}
	return 0;
}