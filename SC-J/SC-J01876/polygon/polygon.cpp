#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(a[1]+a[2]>2*max(a[1],a[2])){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(n==3){
		int ans=0;
		if(a[1]+a[2]>2*max(a[1],a[2])){
			ans++;
		}
		if(a[3]+a[2]>2*max(a[3],a[2])){
			ans++;
		}
		if(a[1]+a[3]>2*max(a[1],a[3])){
			ans++;
		}
		if(a[1]+a[3]>2*max(max(a[1],a[3]),a[2])){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,a[i]);
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>maxx*2){
			ans++;
		}
	}
	int tot=1;
	for(int i=1;i<=n-1;i++){
		tot*=i;
		tot%=998244353;
	}
	ans+=(tot-n);
	cout<<ans;
	return 0;
}