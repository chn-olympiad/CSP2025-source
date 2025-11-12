#include<bits/stdc++.h>
using namespace std;
int a[10000];
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cout<<(n+1)*n/2;
	return 0;
}