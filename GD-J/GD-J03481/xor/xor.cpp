#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],x,y;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) x++;
		if(a[i]==1) y++;
	
	if(k==0) cout<<x;
	if(k==1) cout<<y; 
	return 0;
	
} 
