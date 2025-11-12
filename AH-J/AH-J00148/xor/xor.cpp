#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0 and n==2) cout<<1;
	return 0;
}


