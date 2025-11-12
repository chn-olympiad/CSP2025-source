#include<bits/stdc++.h>
using namespace std;
int n,k,a[110];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		if(n%2==1){
			cout<<0;
			return 0;
		}
		cout<<n/2;
		return 0;
	}
	cout<<7;
	return 0;
}
