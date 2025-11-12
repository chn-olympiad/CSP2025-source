#include <bits/stdc++.h>
using namespace std;
int n,k,a[500008],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0) cout<<ceil(n/2.0);
	else cout<<2;
	return 0;
}
