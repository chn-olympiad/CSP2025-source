#include <bits/stdc++.h>
using namespace std;
int a[200009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans_0=0,ans_1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) ans_1++;
		if(a[i]==0) ans_0++;
	}
	if(k==0) cout<<ans_0;
	if(k==1) cout<<ans_1;
	return 0;
}
