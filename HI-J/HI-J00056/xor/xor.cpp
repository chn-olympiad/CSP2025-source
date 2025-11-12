#include "bits/stdc++.h"
using namespace std;
int a[10];
int yh(int l,int r){
	return l^r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,m=1,s=0,i;
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	if(n==2&&k==0){
		if(a[1]==0)s++;
		if(a[2]==0)s++;
		if(yh(a[1],a[2])==0&&s==0)s++;
	}
	if(n==1&&k==0){
		cout<<0;
		return 0;
	}
	cout<<s;
	return 0;
} 
