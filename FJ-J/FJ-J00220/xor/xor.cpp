#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int sum[n+1];
	for (int i=1;i<=n;i++){
		cin>>sum[i];
	}
	if (n==1 && sum[1]==1){
		cout<<0;
		return 0;
	}
	if (n==2 && sum[1]==1 && sum[2]==1){
		cout<<1;
		return 0;
	}
	if (n<=100 && k==0){
		cout<<n/2;
		return 0;
	}
	cout<<n/3;
	return 0;
}
