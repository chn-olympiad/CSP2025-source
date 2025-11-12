#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	int n,s=0,t=0;
	cin>>n;
	n<=5000;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]<=5000;
		s+=a[i];
		t++;
	}
	cout<<t;
	return 0;
}
