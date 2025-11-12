#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			f=0;
		}
	}
	if(f==1){
		if(k==1){
			cout<<n;
		}
		else{
			cout<<0;
		}
	}
	return 0;
} 
