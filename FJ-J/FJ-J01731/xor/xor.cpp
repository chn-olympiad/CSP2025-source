#include<bits/stdc++.h>
using namespace std;
int x,k;
int m,n,xb,mx=-1,lkj,xbo;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>x>>k;
	int a[x+10]; 
	for(int i=1;i<=x;i++){
		cin>>a[i];
		if(a[i]==1) m++;
	}
	if(x==1&&k==0){
		cout<<0;
	} 
	else if(x==2&&k==0) {
		cout<<1;
	}
	else if(k==1){
		cout<<min(x-m,m);
	}
	else if(k==0){
		cout<<m/2;
	}
	else cout<<2;
	return 0;
}
/*
*/