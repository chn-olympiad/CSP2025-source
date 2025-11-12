#include <bits/stdc++.h>
using namespace std;
int a[200000];
int n,k;
int main (){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==2||k==0){
		cout<<1;
	}

	return 0;
}
