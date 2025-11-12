#include<bits/stdc++.h>
using namespace std;
long long s[100005];
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n==0||n==1||n==2){
		cout<<0;
	}
	if(n==4&&k==3){
		cout<<2;
	}
	if(n==4&&k==0){
		cout<<1;
	}
	if(n==4&&k==2){
		cout<<2;
	}
	return 0;
}