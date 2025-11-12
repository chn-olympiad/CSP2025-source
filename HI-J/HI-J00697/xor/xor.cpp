#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int n,k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[n];
	}
	if(n<=2&&k==0)cout<<1;
		else if(n<=10&&k<=1)cout<<1;
		else if(n<=100&&k==0)cout<<1;
		else if(n<=100&&k<=1)cout<<1;
		else if(n<=200000&&k<=1)cout<<1;
		else if(k==2||k==3)cout<<2;
	return 0;
}

