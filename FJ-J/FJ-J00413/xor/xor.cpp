#include<bits/stdc++.h>
using namespace std;//Ã»¿´¶® 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int m[n];
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	cout<<n/k;
	return 0;
} 
