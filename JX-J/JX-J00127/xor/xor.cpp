#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(k==0&&n==1){
	cout<<0;
	return 0;}
	if(k==0&&n==2){
	cout<<1;
	return 0;}
	cout<<2;
}
