#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000002],b[1000002];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>a[i]>>b[i]>>t;
	}
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=n;i>n/2;i--){
		ans+=a[i];
	}
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
