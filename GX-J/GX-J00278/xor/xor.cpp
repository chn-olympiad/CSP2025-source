#include <bits/stdc++.h>
using namespace std;
int n,k,m;
int a[100005];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];}
	sort(a,a+n);
	for(int ii=0;ii<n;ii++){
		m+=a[ii];
		m=m/k;}
	if (m==0){cout<<a[n-1];}
	else if (n>m){cout<<a[1];}
	else {cout<<m;}
	return 0;}
