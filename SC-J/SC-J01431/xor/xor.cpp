#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool v=true;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		if(v&&(a[i]==1||a[i]==0))
		else v=false;
	}
	int ans=0;
	if(n<=2&&k==0){
		if(a[1]==0) ans++;
		if(a[2]==0) ans++;
		if(a[1]==a[2]) ans++;
		cout<<ans;
		returtn 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]) ans++;
			else if(a[i]==0) ans++;
		} 
		cout<<ans;
		return;
	}
	if(v&&k==1){
		int tmp=0;
		for(int i=1;i<=n;i++){
			tmp+=a[i];
			if(tmp%2==1){
				ans++;
				tmp=0;
			}
		}
		cout<<ans;
	}
	
	return 0;
}