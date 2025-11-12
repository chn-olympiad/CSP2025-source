#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[514514];int n,k,maa=0,mii=11451411451;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maa=max(maa,a[i]);
		mii=min(mii,a[i]);
	}
	if(k==0&&maa==1&&mii==1){
		cout<<n/2;
		return 0;
	}
	if(k<=1&&maa<=1){
		int ans=0;
		a[n+1]=11451414;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else if(a[i]==1&&a[i+1]==1)ans++,i++;
			}
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
				else if(a[i]==0&&a[i+1]==0)ans++,i++;
			}
		}cout<<ans;
		return 0;
	}
	return 0;
}
