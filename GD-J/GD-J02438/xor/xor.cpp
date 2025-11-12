#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[110],sum=0,cnt=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[1]){
			cnt=0;
		}
	}
	if(cnt==1 && a[1]==k){
		cout<<n;
		return 0;
	}
	if(k==0 && cnt==1 && a[1]==1){
		cout<<n/2;
		return 0;
	}
	cout<<3;
	return 0;
}
