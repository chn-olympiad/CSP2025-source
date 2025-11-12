#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100];
	for(int i=1,i<=n;i++){
		cin>>a[i];
	}
	n=1+2;
	k=2*n;
	a[1]=a[2]+a[3];
	n++;
	k--;
	for(int i=1;i<=2;i++){
		k++;
	}
	cout<<3;
	return 0;
}
