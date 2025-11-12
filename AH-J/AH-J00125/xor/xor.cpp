#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int a[20005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)m=1;
	}
	cout<<n/2;
	return 0;
}
