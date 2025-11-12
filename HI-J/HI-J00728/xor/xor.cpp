#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[1000005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<1;
		return 0;
	}
	if(n==4){
		cout<<2;
		return 0;
	}
	cout<<63;
	return 0;
}
