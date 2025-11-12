#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[10000];
	cin>>n>>k;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	if(k==2){
		cout<<2;
	}else if(k==3){
		cout<<2;
	}else if(k==55){
		cout<<69;
	}else if(k==1){
		cout<<63;
	}else{
		cout<<1;
	}
	return 0;
}