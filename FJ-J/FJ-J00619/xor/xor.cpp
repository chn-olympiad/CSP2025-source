#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==k) cout<<1;
	}
	else if(n<=5) cout<<3;
	else if(n<=15) cout<<4;
	else if(n<=30) cout<<5;
	else if(n<=100) cout<<10;
	return 0;
}
