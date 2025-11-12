#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000008],s,b,q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) s++;
		if(a[i]==1) b++;
		if(a[i]==2) q++;
	}
	if(k==0) cout<<s;
	if(k==1) cout<<b;
	if(k==2) cout<<q+b/2;
} 
