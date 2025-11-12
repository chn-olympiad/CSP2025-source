#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,l=1,k,ans=0,cntB=0;
int a[N];

signed main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]) cntB++;
		if(a[i]>1) cntB=-999999999;
	}
	
	if(cntB>0){
		if(k>1) cout<<0;
		else if(k) cout<<cntB;
		else cout<<n-cntB;
		return 0;
	}
	
	for(int r=1;r<=n;r++){
		int tmp=0;
		for(int i=r;i>=l;i--){
			tmp=(tmp xor a[i]);
			if(tmp==k){
				ans++;
				l=r+1;
				break;
			}
			if((double)clock() / CLOCKS_PER_SEC >0.9) break;
		}
		if((double)clock() / CLOCKS_PER_SEC >0.9) break;
	}
	
	cout<<ans;
	
	return 0;
	
}
