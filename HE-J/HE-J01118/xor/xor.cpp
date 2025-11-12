#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],sum=0;;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&k==a[1]){
		cout<<1;
	}
	else if(k==0){
		for(int i=2;i<=n;i+2) sum+=n/i; 
		cout<<sum;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
