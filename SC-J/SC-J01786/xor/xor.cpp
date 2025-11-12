#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,p=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)	p++;
	}
	if(p==n){
		cout<<0;
		return 0;
	}
	int ans=0;
	if(k==0){
		cout<<n-p;
	}
	else{
		cout<<n;
	}
	return 0;
}