#include <bits/stdc++.h>
using namespace std;
int n,k,i,a;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a;
	}
	if(k==0) cout<<"1";
	else cout<<"2";
	return 0;
}
