#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],count1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1) count1++;
	}
	if(k=1) cout<<count1;
	else cout<<n/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
