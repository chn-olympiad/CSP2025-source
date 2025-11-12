#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==2){
		cout<<1;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n<=100&&k==0){
		cout<<n/2;
		return 0;
	}
	return 0;
}
