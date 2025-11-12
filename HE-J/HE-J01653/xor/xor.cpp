#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,bt=0,a[10101]={};
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bt=max(bt,a[i]);
	}
	cout<<bt;
	return 0;
}
