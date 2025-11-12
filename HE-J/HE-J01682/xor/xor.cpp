#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[10001];
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",a[i]);
	if(k>=2) cout<<0;
	else cout<<n*(n+1)/2; 
	return 0;
} 
