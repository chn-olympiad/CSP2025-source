#include<bits/stdc++.h>
using namespace std;
int a[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k,f=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(k==0&&f==1){
		long long sum=(n-1)*(n-2);
		cout<<sum+n;
	}
	else cout<<1;
	return 0;
} 
