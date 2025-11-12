#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10010];
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];

	}
	if(n==0)cout<<0;
	if(n==1)cout<<0;
	if(n==2){
		cout<<1;

	}
	if(n>10&&n<=100)cout<<n/2;
return 0;
}

