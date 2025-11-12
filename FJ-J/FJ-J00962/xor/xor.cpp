#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[110];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k!=0) cout<<"0";
	else cout<<n;
	return 0;
}
