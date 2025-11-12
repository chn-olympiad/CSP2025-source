#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=500005;
int n,k,a[MAXN];
void solve();
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
void solve(){
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]&&a[i]!=0&&a[i+1]!=0){
				ans++;
				i++;
			}
			if(a[i]==0) ans++;
		}
		cout<<ans;
		return ;
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]+1==a[i+1]&&a[i]%2==0&&a[i]!=0){
				ans++;
				i++;
			}
			if(a[i]==1) ans++;
		}
		cout<<ans;
		return ;
	}
	bool f=true;
	for(int i=1;i<=n;i++){
		int tj=a[i];
		if(a[i]==k||tj==k){
			ans++;
			tj=0;
		}
		else{
			for(int j=i+1;j<=n;j++){
				tj^=a[j];
				if(tj==k){
					ans++;
					i=j;
					tj=0;
					break;
				}
			}
		}
	}
	cout<<ans;
	return ;
}

