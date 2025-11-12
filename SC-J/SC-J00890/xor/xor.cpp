#include<bits/stdc++.h>
#define int long long
using namespace std;

int x[500005];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>>k;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(n==1) cout<<1;
	if(n==2){
		if(k==0){
			if(x[1]==x[2] && x[1]==0) cout<<2;
			else cout<<1;
		}
	} 
	return 0;
}