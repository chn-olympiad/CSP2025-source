#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,m[500010],s=0,d=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		d=d^m[i];
		if(d==k){
			d=0;
			s++;}}
	cout<<s;
	return 0;}