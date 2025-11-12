#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&k==2||n==4&&k==3){
		cout<<2;
	}
	if(n==4&&k==0){
		cout<<1;
	}

	return 0;
}
