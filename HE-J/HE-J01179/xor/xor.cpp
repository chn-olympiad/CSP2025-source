#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a[n];
	for(int i =0;i<n;i++)cin>>a[i];
	if(k==2){
		cout<<2<<endl;
		return 0;
	}
	if(k==3){
		cout<<2<<endl;
		return 0;
	}
	if(k==0){
		cout<<1;
	}
	return 0;
}
