#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int maxa=0,n,a[5005],add=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		add=add+a[i];
		}
	if(n==3&&add>maxa*2){
		cout<<1;
		return 0;
		}
	if(n==3&&add<=maxa*2){
		cout<<0;
		return 0;
		}
	cout<<o;
	return 0;

}
