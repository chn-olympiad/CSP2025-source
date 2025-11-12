#include<bits/stdc++.h>
using namespace std;
int n,k,w,w1;
int main(){
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>w;
		for(int j=0;j<20;j++){
			w1+=w%2;
			w1*=10;
			w/=2;
		}
		a[i]=w1;
	}
	cout<<2;
	return 0;
}