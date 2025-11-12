#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1000000];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k%2==0) cout<<n/2;
	return 0;
}