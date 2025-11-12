#include<bits/stdc++.h>
using namespace std;
int n,k,a[91],num;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==k){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	else if(n==2){
		if(a[1]==k){
			num++;
		}
		if(a[2]==k){
			num++;
		}
		if(a[1]==a[2]){
			num++;
		}
		cout<<num;
	}
	return 0;
}
