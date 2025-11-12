#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(i<=n && i>=1) cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
