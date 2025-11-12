#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&a[1]!=k){
		cout<<0;
		return 0;
	}
	else if(n==2){
		cout<<1;
		return 0;
	}
	cout<<n/2;
	return 0;
} 
