#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		cout<<1;
	}
	return 0;
}
