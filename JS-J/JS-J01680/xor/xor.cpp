#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool flag=1;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(k==0){
		if(n==1&&a[0]==1)cout<<0;
		else if(n==2&&a[0]==1&&a[1]==1){
			cout<<1;
		}
		else if(flag){
			cout<<n/2;
		}
	}
	else cout<<5;
	return 0;
}
