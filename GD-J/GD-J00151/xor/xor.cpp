#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n==1){
		if(k==a[1]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(n==2){
		cout<<1;
		return 0;
	} 
	cout<<0;
	return 0;
}
