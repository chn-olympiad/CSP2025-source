#include<bits/stdc++.h>
using namespace std;
long long n,k,aa,bb;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a==0){
			aa++;
		}
		if(a==1){
			bb++;
		}
	}
	if(k==0){
		cout<<aa;
	}
	if(k==1){
		cout<<bb;
	}
	return 0;
}
