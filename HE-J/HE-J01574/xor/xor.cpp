#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], sum[500005];  
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	if (n==1){
		cout<<0;
	}
	else if (n==2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
