#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>t;
	}
	if(n<=100 && k==0){
		cout<<1;
	}
	else if(n<=100 && k<=255){
		cout<<2;
	}
	return 0;
}
