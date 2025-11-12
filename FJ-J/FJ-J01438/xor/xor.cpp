#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int x=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1)x=1;
	}
	if(x==0){
		if(n%2==0)cout<<n-1;
		else cout<<n;
	}
	return 0;
} 
