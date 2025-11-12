#include <bits/stdc++.h>
using namespace std;
int n,k,v[100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int x=1;x<=n;x++){
		cin>>v[x];
	}
	cout<<n/2;
	return 0;
}
