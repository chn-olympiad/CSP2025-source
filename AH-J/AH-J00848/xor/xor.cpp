#include<bits/stdc++.h>
using namespace std;
int n,k,a,ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a;
		if(a==k) ans++;
	}
	if(k>1) ans++;
	cout<<ans;
	return 0;
}
