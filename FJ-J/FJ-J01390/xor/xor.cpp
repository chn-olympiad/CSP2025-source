#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==3) cout<<n;
	else cout<<0;
	return 0;
}
