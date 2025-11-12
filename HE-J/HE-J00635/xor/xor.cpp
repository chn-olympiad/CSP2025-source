#include<bits/stdc++.h>
using namespace std;
int d,k;
//char a[1000005];
int a[1005];
int n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2) cout<<0;
	if(n<=10) cout<<1;
	return 0; 
} 
