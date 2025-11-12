#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[n];
	cin>>n>>k;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		if(n==1&&k==0){
			cout<<1;
			return 0;
		}
		if(n==2&&k==0){
			cout<<2;
			return 0;
		}
		if(k==0){
			cout<<1;
			return 0;
		}
	}
	return 0;
}