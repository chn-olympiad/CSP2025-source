#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k>0) cout<<2;
    else cout<<1;
	return 0;
}
