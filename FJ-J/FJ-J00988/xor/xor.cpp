#include <bits/stdc++.h>
using namespace std;
int a[5000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum==n){
		cout<<0;
	}else if(k==1){
		cout<<sum;
	}else{
		cout<<n-sum;
	}
	return 0;
}

