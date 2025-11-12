#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll=long long;

void solve(){
	int n,k,pp0=0;
	cin>>n>>k;
	vector<int> s(n+8),xo(n+8);
	xo[0]=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		xo[i]=xo[i-1]^s[i];
		if(xo[i]==0) pp0++;
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		int rig=i;
		if(xo[i]==k){
			ans++;
			bool ok=0;
			while(rig<=n&&xo[rig]!=0){
				if((rig==n&&xo[rig]==0)||(rig<n&&xo[rig]==0)) ok=1;
				rig++;
			}
			if(ok) ans++;
		}
		i=rig; 
	}
	if(k==0) cout<<pp0;
	else cout<<ans;
	return;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	solve();
	return 0;
} 
